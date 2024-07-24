/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 18:40:11 by woosupar         ###   ########.fr       */
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
		child_working(data, old_fd, 0, i);
	else
	{	
		if (old_fd != 0)
		{
			close(old_fd[0]);
			free(old_fd);
		}
		data->pids[i] = pid;
		child_wait(data, i, pid);
	}
	return (0);
}

int	child_wait(t_data *data, int i, pid_t pid)
{
	int	j;

	j = -1;
	if (g_signal_num == 130 || g_signal_num == 131)
		kill(-1, g_signal_num - 128);
	if (data->num_pipe == 0)
		waitpid(pid, &g_signal_num, 0);
	else
	{
		while (++j < i)
		{
			if (j == 0)
				waitpid(pid, &g_signal_num, 0);
			waitpid(data->pids[j], &g_signal_num, 0);
		}
	}
	return (0);
}
