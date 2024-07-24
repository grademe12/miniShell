/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 21:39:27 by woosupar         ###   ########.fr       */
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
	// if (data->num_pipe == 0)
	// 	waitpid(pid, &g_signal_num, 0);
	// else
	// {
	// 	while (++j <= i)
	// 	{
	// 		waitpid(data->pids[j], &g_signal_num, 0);
	// 		if (j == i)
	// 			waitpid(pid, &g_signal_num, 0);
	// 	}
	// }
	while (++j <= i)
		waitpid(-1, &g_signal_num, 0);
	(void)data;
	(void)pid;
	return (0);
}
