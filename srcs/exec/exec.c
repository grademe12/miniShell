/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:35 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/18 16:47:42 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec(t_data *data)
{
	int		val;

	val = check_builtin(data);
	data->pids = (pid_t *)malloc(sizeof(pid_t) * (data->num_pipe + 1));
	if (data->pids == 0)
		exit (1);
	if (val != -1)
		builtin_red_exe(data, val);
	else
		piping(data);
	free(data->pids);
	return (0);
}

int	check_builtin(t_data *data)
{
	char	*cmd;
	
	cmd = data->argv[0];
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (2);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (3);
	if (ft_strcmp(cmd, "export") == 0)
		return (4);
	if (ft_strcmp(cmd, "unset") == 0)
		return (5);
	if (ft_strcmp(cmd, "env") == 0)
		return (6);
	if (ft_strcmp(cmd, "exit") == 0)
		return (7);
	return (-1);
}

int	exe_builtin(t_data *data, int val)
{
	if (val == -1)
		return (-1);
	if (val == 1)
		echo_builtin(data);
	if (val == 2)
		cd_builtin(data);
	if (val == 3)
		pwd_builtin(data);
	if (val == 4)
		export_builtin(data);
	if (val == 5)
		unset_builtin(data);
	if (val == 6)
		env_builtin(data);
	if (val == 7)
		exit_builtin(data);
	return (0);
}