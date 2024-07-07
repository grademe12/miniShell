/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/07 12:00:49 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	t_data		*phrase;
	int			**old_fd;
	int			i;

	i = 0;
	*old_fd = 0;
	phrase = data;
	while (phrase != 0)
	{
		if (i == data->num_pipe)
			last_child(data, i, old_fd);
		make_child(data, i, old_fd);
		phrase = data->next;
		i++;
	}
	i = 0;
	while (i < data->num_pipe)
	{
		waitpid(data->pids[i], 0, 0);
		i++;
	}
}

int	make_child(t_data *data, int i, int **old_fd)
{
	int		new_fd[2];
	pid_t	pid;

	if (pipe(new_fd) == -1)
		inner_function_error("pipe fail\n");
	pid = fork();
	if (pid == -1)
		inner_function_error("fork fail\n");
	if (pid == 0)
		child_working(data, old_fd, new_fd);
	else
	{
		if (data->num_pipe == 0)
			close(new_fd[0]);
		if (*old_fd != 0)
			close(*old_fd[0]);
		close(new_fd[1]);
		data->pids[i] = pid;
	}
	return (0);
}

int	child_working(t_data *data, int **old_fd, int *new_fd)
{
	t_token		*cur;

	cur = data->zero_token;
	while (cur != 0)
	{
		if (check_red(data, cur) != 0)
		{	
			strerror(errno);
			return (errno); //exit(1);
		}
		cur = cur->next;
	}
	remake_argv(data);
	if (is_path(data->argv[0]) == -1) // 상대/절대경로 이후 실행파일이 오면?
	{
		data->argv[0] = make_path(data->argv, data->envp);
		free(data->zero_token->token);
		data->zero_token->token = data->argv[0]; // 필요 없을지도
		if (data->argv[0] == 0)
			return (127);
	}
	check_cmd_valid(data, old_fd, new_fd);
	return (0);
}

int	dup_fd(t_data *data, int **old_fd, int *new_fd)
{
	if (data->num_pipe == 0)
		close(new_fd[1]);
	close(new_fd[0]);
	if (dup2(new_fd[1], STDOUT_FILENO) == -1)
	{
		ft_errnum(9);
		exit (9);
	}
	close(new_fd[1]);
	if (*old_fd != 0)
	{
		if (dup2(*old_fd[0], STDIN_FILENO) == -1)
		{
			ft_errnum(9);
			exit(9);
		}
		close(*old_fd[0]);
	}
	*old_fd = new_fd;
	if (execve(data->argv[0], data->argv, data->envp) == -1)
	{
		ft_printf("execve fail\n");
		exit (1);
	}
	return (0);
}

