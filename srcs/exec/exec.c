/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:35 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 14:02:21 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec(t_data *data)
{
	int		builtin_ret;
	t_data	*cur;

	builtin_ret = 0;
	if (data->num_pipe == 0)
		builtin_ret = builtin_loop(data);
	cur = data;
	if (builtin_ret == -1 || data->num_pipe != 0)
	{
		data->pids = (pid_t *)malloc(sizeof(pid_t) * data->num_pipe + 1);
		if (data->pids == 0)
			inner_function_error("malloc fail\n");
		while (cur != 0)
		{
			cur->pids = data->pids;
			cur = cur->next;
		}
		piping(data);
		free(data->pids);
	}
	return (0);
}

int	builtin_loop(t_data *data)
{
	int		val;
	int		err;
	char	*cmd;

	err = 0;
	val = check_builtin(data->argv[0]);
	if (val != -1)
		err = builtin_red_exe(data, val);
	if (err != 0)
	{
		cmd = err_get_cmd(val);
		printf("bfsh: %s: %s: %s\n", cmd, data->argv[1], strerror(err));
		return (err);
	}
	return (val);
}

char	*err_get_cmd(int val)
{
	if (val == 1)
		return ("echo");
	if (val == 2)
		return ("cd");
	if (val == 3)
		return ("pwd");
	if (val == 4)
		return ("export");
	if (val == 5)
		return ("unset");
	if (val == 6)
		return ("env");
	if (val == 7)
		return ("exit");
	return (0);
}

int	check_builtin(char *cmd)
{	
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
	int	ret_code;

	if (val == 1)
		ret_code = echo_builtin(data);
	if (val == 2)
		ret_code = cd_builtin(data);
	if (val == 3)
		ret_code = pwd_builtin(data);
	if (val == 4)
		ret_code = export_builtin(data);
	if (val == 5)
		ret_code = unset_builtin(data);
	if (val == 6)
		ret_code = env_builtin(data);
	if (val == 7)
		ret_code = exit_builtin(data);
	return (ret_code);
}
