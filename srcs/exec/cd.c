/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 20:31:12 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_builtin(t_data *data)
{
	if (data->argv[1] == 0)
		return (cd_no_arg(data));
	if (cd_builtin2(data) == RET_FAIL)
		return (RET_FAIL);
	change_env_pwd(data, "PWD=");
	g_signal_num = 0;
	return (0);
}

int	cd_no_arg(t_data *data)
{
	char	*home;

	home = get_home_path(data);
	if (home == 0)
	{
		ft_putstr_fd("bfsh: cd: HOME not set\n", 2);
		g_signal_num = 1;
		return (RET_FAIL);
	}
	if (cd_builtin_check_valid(home) != 0)
	{
		g_signal_num = 1;
		free(home);
		return (RET_FAIL);
	}
	change_env_pwd(data, "OLDPWD=");
	chdir(home);
	change_env_pwd(data, "PWD=");
	free(home);
	g_signal_num = 0;
	return (0);
}

int	cd_builtin2(t_data *data)
{
	char	cwd[4096];

	if (ft_strlen(data->argv[1]) > 4096)
	{
		cmd_not_found("cd", strerror(ENAMETOOLONG), 1);
		g_signal_num = 1;
		return (RET_FAIL);
	}
	if (getcwd(cwd, 4096) == 0)
	{
		ft_putendl_fd("cd: error retrieving current directory: getcwd: cannot \
access parent directories: No such file or directory", 2);
		return (RET_FAIL);
	}
	if (cd_builtin_check_valid(data->argv[1]) != 0)
	{
		g_signal_num = 1;
		return (RET_FAIL);
	}
	change_env_pwd(data, "OLDPWD=");
	chdir(data->argv[1]);
	return (0);
}

int	cd_builtin_check_valid(char *str)
{
	if (access(str, F_OK) == -1)
	{
		cmd_not_found("cd", "No such file or directory", 1);
		return (errno);
	}
	if (check_dir_file(str) == FILETYPE)
	{
		cmd_not_found("cd", "Not a directory", 1);
		return (ENOTDIR);
	}
	if (access(str, X_OK) == -1)
	{
		cmd_not_found("cd", "Permission denied", 1);
		return (errno);
	}
	return (0);
}

int	change_env_pwd(t_data *data, char *str)
{
	int		target_idx;
	char	*target;
	char	cwd[4096];

	target_idx = check_dup(data, str, ft_strlen(str) - 1);
	if (target_idx == -1)
		make_oldpwd(data, str);
	else
	{
		free(data->envp[target_idx]);
		getcwd(cwd, 4096);
		target = ft_strjoin(str, cwd);
		data->envp[target_idx] = target;
	}
	free(data->pwd);
	data->pwd = ft_strdup(cwd);
	return (0);
}
