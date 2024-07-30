/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:11:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/28 21:55:28 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	child_exec(t_data *data)
{
	int	builtin_num;

	builtin_num = check_builtin(data->argv[0]);
	if (builtin_num != NOT_BUILTIN)
	{
		exe_builtin(data, builtin_num);
		exit(0);
	}
	if (execve(data->argv[0], data->argv, data->envp) == -1)
		child_err_exit(errno, data->argv[0]);
	return (0);
}

int	last_child(t_data *data, int i, int *old_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		inner_function_error("fork fail\n");
	if (pid == 0)
		child_working(data, old_fd, 0);
	else
	{
		if (old_fd != 0)
		{
			close(old_fd[0]);
			free(old_fd);
		}
		g_signal_num = 0;
		child_wait(i);
	}
	return (0);
}

int	child_wait(int i)
{
	int	j;
	int	status;

	j = -1;
	status = 0;
	while (++j <= i)
		waitpid(-1, &status, 0);
	if (WIFSIGNALED(status) == TRUE)
		g_signal_num = 128 + WTERMSIG(status);
	if (WIFEXITED(status) == TRUE)
		g_signal_num += WEXITSTATUS(status);
	return (0);
}
