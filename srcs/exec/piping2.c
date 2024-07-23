/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 17:15:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	last_child(t_data *data, int i, int *old_fd, int *new_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		inner_function_error("fork fail\n");
	if (pid == 0)
	{
		close(new_fd[1]);
		close(new_fd[0]);
		child_working(data, old_fd, 0, -1);
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
	}
	else
		child_wait(data, i, pid, old_fd);
	return (0);
}

int	child_wait(t_data *data, int i, pid_t pid, int *old_fd)
{
	int	j;

	if (i == 0)
		waitpid(pid, 0, 0);
	j = 0;
	while (j < i)
	{
		waitpid(data->pids[j], 0, 0);
		j++;
		if (j == i - 1)
		waitpid(pid, 0, 0);
	}
	if (old_fd != 0)
		close(old_fd[0]);
	return (0);
}
