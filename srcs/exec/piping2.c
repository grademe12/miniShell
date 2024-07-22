/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/22 17:43:05 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	last_child(t_data *data, int i, int **old_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		inner_function_error("fork fail\n");
	if (pid == 0)
	{
		child_working(data, old_fd, 0);
		if (data->num_pipe != 0)
		{
			if (dup2(*old_fd[0], STDIN_FILENO) == -1)
				child_err_exit(errno);
			close(*old_fd[0]);
		}
		if (execve(data->argv[0], data->argv, data->envp) == -1)
			child_err_exit(errno);
	}
	else
	{
		child_wait(data, i, pid);
		if (data->num_pipe != 0)
			close(*old_fd[0]);
	}
	return (0);
}

int	child_wait(t_data *data, int i, pid_t pid)
{
	int	j;

	j = 0;
	while (j < i)
	{
		waitpid(data->pids[j], 0, 0);
		j++;
	}
	waitpid(pid, 0, 0);
	return (0);
}