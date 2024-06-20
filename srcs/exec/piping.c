/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/20 20:13:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	pid_t	fastest_exit_pid;
	t_data	*phrase;
	int		**old_fd;
	int		i;

	i = 0;
	phrase = data;
	while (phrase != 0)
	{
		make_child(data, i, old_fd);
		phrase = data->next;
	}
	i = 0;
	fastest_exit_pid = wait(0);
	if (fastest_exit_pid == data->pids[data->num_pipe])
	{
	}
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
		child_working(data, i, old_fd, new_fd);
	else
	{
		if (data->num_pipe == 0)
		{
			close(new_fd[1]);
			data->pids[i] = pid;
		}
	}
	return (0);
}

int	child_working(t_data *data, int i, int *old_fd, int *new_fd)
{
	t_token	*cur;

	cur = data->zero_token;
	while (cur != 0)
	{
		if (check_red(data, cur) != 0)
		{	
			strerror(errno);
			return (errno);
		}
		cur = cur->next;
	}
	if (remake_argv(data) == -1)
	if (is_path(data->argv[0]) == -1)
	{
		data->argv[0] = make_path(data->argv, data->envp);
		free(data->zero_token->token);
		data->zero_token->token = data->argv[0]; // 필요 없을지도
		if (data->argv[0] == 0)
			return (127);
	}
	if (access(data->argv[0], F_OK) == -1)
	{
		printf ("%s: %s", data->argv[0], strerror(errno)); // 버전 통일시키기
		return (errno);
	}
	if (check_dir_file(data->argv[0]) == DIR)
	{
		printf ("%s: %s", data->argv[0], strerror(errno));
		return (errno);
	}
	if (access(data->argv[0], X_OK) == -1)
	{
		printf ("%s: %s", data->argv[0], strerror(errno));
		return (errno);
	}
	child_working2(data, i, old_fd, new_fd);
	return (0);
}

int	child_working2(t_data *data, int i, int *old_fd, int *new_fd)
{
	if (data->num_pipe == 0)
		close(new_fd[1]);
	close(new_fd[0]);
	dup2(new_fd[1], STDOUT_FILENO);
}

int	check_red(t_data *data, t_token *cur)
{
	if (cur->type == INPUT_REDIR)
		return (input_red(cur, INPUT_REDIR));
	if (cur->type == OUTPUT_REDIR)
		return (input_red(cur, OUTPUT_REDIR));
	if (cur->type == APPEND_REDIR)
		return (input_red(cur, APPEND_REDIR));
	if (cur->type == HEREDOC)
		return (heredoc_red(cur));
	return (0);
}
