/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:35 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/12 18:36:33 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec()
{
	int	val;

	val = check_builtin();
	if (val != -1)
		exe_builtin(val);
	return (0);
}

int	check_builtin()
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 2) == 0)
		return (2);
	if (ft_strncmp(cmd, "pwd", 3) == 0)
		return (3);
	if (ft_strncmp(cmd, "export", 6) == 0)
		return (4);
	if (ft_strncmp(cmd, "unset", 5) == 0)
		return (5);
	if (ft_strncmp(cmd, "env", 3) == 0)
		return (6);
	if (ft_strncmp(cmd, "exit", 4) == 0)
		return (7);
	return (-1);
}

int	exe_builtin(int val)
{
	if (val == -1)
		return (-1);
	if (val == 1)
		echo_builtin();
	if (val == 2)
		cd_builtin();
	if (val == 3)
		pwd_builtin();
	if (val == 4)
		export_builtin();
	if (val == 5)
		unset_builtin();
	if (val == 6)
		env_builtin();
	if (val == 7)
		exit_builtin();
	return (0);
}