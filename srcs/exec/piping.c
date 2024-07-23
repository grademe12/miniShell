/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 16:50:59 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	t_data		*phrase;
	int			new_fd[2];
	int			*old_fd;
	int			i;

	i = 0;
	phrase = data;
	old_fd = 0;
	while (phrase != 0)
	{
		if (pipe(new_fd) == -1)
			inner_function_error("pipe fail\n");
		if (i == data->num_pipe)
			last_child(data, i, old_fd, new_fd);
		else
			make_child(data, i, old_fd, new_fd);
		phrase = data->next;
		old_fd = new_fd;
		i++;
	}
	return (0);
}

int	make_child(t_data *data, int i, int *old_fd, int *new_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		inner_function_error("fork fail\n");
	if (pid == 0)
		child_working(data, old_fd, new_fd, i);
	else
	{
		if (i != 0)
			close(old_fd[0]);
		close(new_fd[1]);
		data->pids[i] = pid;
	}
	return (0);
}

int	child_working(t_data *data, int  *old_fd, int *new_fd, int i)
{
	t_token		*cur;

	cur = data->zero_token;
	while (cur != 0)
	{
		if (check_red(data, cur) != 0)
			ft_putstr_fd(strerror(errno), 2);
		cur = cur->next;
	}
	remake_argv(data);
	if (is_path(data->argv[0]) == -1) // 상대/절대경로 이후 실행파일이 오면?
	{
		data->argv[0] = make_path(data->argv, data->envp);
		if (data->argv[0] == 0)
			return (127);
	}
	check_cmd_valid(data, old_fd, new_fd, i);
	return (0);
}

int	check_cmd_valid(t_data *data, int *old_fd, int *new_fd, int i)
{
	if (access(data->argv[0], F_OK) == -1) // 파일 존재하지 않음
		child_err_exit(errno);
	if (check_dir_file(data->argv[0]) == DIR) // 커맨드가 파일이 아닌 디렉토리임
		child_err_exit(errno);
	if (access(data->argv[0], X_OK) == -1) // 파일은 존재하나, 권한이 없음
		child_err_exit(errno);
	if (new_fd != 0)
		dup_fd(data, old_fd, new_fd, i);
	return (0);
}

int	dup_fd(t_data *data, int *old_fd, int *new_fd, int i)
{
	close(new_fd[0]);
	if (dup2(new_fd[1], STDOUT_FILENO) == -1)
		child_err_exit(errno);
	close(new_fd[1]);
	if (old_fd != 0)
	{
		if (dup2(old_fd[0], STDIN_FILENO) == -1)
			child_err_exit(errno);
		close(old_fd[0]);
	}
	if (builtin_loop(data) != -1)
		exit(0);
	if (execve(data->argv[0], data->argv, data->envp) == -1)
		child_err_exit(errno);
	(void)i;
	return (0);
}

