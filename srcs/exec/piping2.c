/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 22:46:57 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	last_child(t_data *data, int i, int *old_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		inner_function_error("fork fail\n");
	if (pid == 0)
	{
		child_working(data, old_fd, 0, i);
	}
	else
		child_wait(data, i, pid, old_fd);
	return (0);
}

int	child_wait(t_data *data, int i, pid_t pid, int *old_fd)
{
	int	j;

	j = 0;
	if (data->num_pipe == 0)
		waitpid(pid, 0, 0);
	else
	{
		while (j < i)
		{
			if (j == 0)
				waitpid(pid, 0, 0);
			waitpid(data->pids[j], 0, 0);
			j++;
		}
	}
	if (old_fd != 0)
	{
		close(old_fd[0]);
		free(old_fd);
	}
	return (0);
}
