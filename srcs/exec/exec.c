/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:35 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/27 13:59:37 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec(t_data *data)
{
	int		builtin_num;
	int		stdin;
	int		stdout;

	builtin_num = 0;
	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	if (data->num_pipe == 0)
		builtin_num = builtin_loop(data);
	if (builtin_num == NOT_BUILTIN || data->num_pipe != 0)
		piping(data);
	if (dup2(stdin, STDIN_FILENO) == -1)
		inner_function_error("dup2 fail\n");
	if (dup2(stdout, STDOUT_FILENO) == -1)
		inner_function_error("dup2 fail\n");
	close(stdin);
	close(stdout);
	rm_heredoc();
	return (0);
}

int	builtin_loop(t_data *data)
{
	int		builtin_num;
	int		red_builtin_ret;
	int		exe_builtin_ret;

	exe_builtin_ret = 0;
	red_builtin_ret = 0;
	builtin_num = check_builtin(data->argv[0]);
	if (builtin_num == NOT_BUILTIN)
		return (NOT_BUILTIN);
	red_builtin_ret = builtin_red(data);
	if (red_builtin_ret != 0)
		return (RET_FAIL);
	remake_argv(data);
	exe_builtin_ret = exe_builtin(data, builtin_num);
	if (exe_builtin_ret != 0)
		return (RET_FAIL);
	g_signal_num = 0;
	return (0);
}

int	builtin_red(t_data *data)
{
	t_token	*cur;
	int		ret_code;

	cur = data->zero_token;
	while (1)
	{
		ret_code = check_red(data, cur);
		if (ret_code != 0)
			return (ret_code);
		cur = cur->next;
		if (cur == 0)
			break ;
	}
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
	return (NOT_BUILTIN);
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
