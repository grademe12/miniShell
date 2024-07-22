/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 02:35:33 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	t_data		*phrase;
	int			**old_fd;
	int			i;

	i = -1;
	old_fd = (int **)malloc (sizeof(int *));
	*old_fd = (int *)malloc (sizeof(int) * 2);
	if (old_fd == 0 || *old_fd == 0)
		inner_function_error("malloc fail\n");
	phrase = data;
	while (phrase != 0)
	{
		if (++i == data->num_pipe)
			last_child(data, i, old_fd);
		else
			make_child(data, i, old_fd);
		phrase = data->next;
	}
	free(old_fd);
	free(*old_fd);
	return (0);
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
			strerror(errno);
		cur = cur->next;
	}
	remake_argv(data);
	if (is_path(data->argv[0]) == -1) // 상대/절대경로 이후 실행파일이 오면?
	{
		data->argv[0] = make_path(data->argv, data->envp);
		if (data->argv[0] == 0)
			return (127);
	}
	check_cmd_valid(data, old_fd, new_fd);
	return (0);
}

int	dup_fd(t_data *data, int **old_fd, int *new_fd)
{
	// if (data->num_pipe == 0)
	// 	close(new_fd[1]); 진입 불가능한 코드
	close(new_fd[0]);
	if (dup2(new_fd[1], STDOUT_FILENO) == -1)
		child_err_exit(errno);
	close(new_fd[1]);
	if (*old_fd != 0)
	{
		if (dup2(*old_fd[0], STDIN_FILENO) == -1)
			child_err_exit(errno);
		close(*old_fd[0]);
	}
	*old_fd = new_fd;
	if (execve(data->argv[0], data->argv, data->envp) == -1)
		child_err_exit(errno);
	return (0);
}

