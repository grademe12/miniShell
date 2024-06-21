/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/21 19:33:46 by woosupar         ###   ########.fr       */
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
		child_wokring(data, old_fd, 0);
		if (dup2(*old_fd[0], STDIN_FILENO) == -1)
		{
			errnum(9);
			exit (9);
		}
		close(*old_fd[0]);
		if (execve(data->argv[0], data->argv, data->envp) == -1)
		{
			ft_printf("execve fail\n");
			exit (1);
		}
	}
	else
		close(*old_fd[0]);
	return (0);
}
