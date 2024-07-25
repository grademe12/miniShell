/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/25 21:39:02 by woosupar         ###   ########.fr       */
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
		child_wait(i);
	}
	return (0);
}

int	child_wait(int i)
{
	int	j;
	int	status;

	j = -1;
	red_err = 0;
	while (++j <= i)
		waitpid(-1, &status, 0);
	g_signal_num += status;
	return (0);
}
