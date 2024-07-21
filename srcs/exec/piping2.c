/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/22 00:39:36 by woosupar         ###   ########.fr       */
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
		data->pids[i] = pid;
		if (data->num_pipe != 0)
			close(*old_fd[0]);
	}
	(void)i;
	return (0);
}
