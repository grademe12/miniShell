/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/29 19:46:28 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_builtin(t_data *data)
{
	int		ret_code;

	ret_code = 0;
	if (data->argv[1] == 0)
		if (cd_no_arg(data) != 0)
			return (RET_FAIL);
	ret_code = cd_builtin2(data);
	change_env_pwd(data, "PWD=");
	return (ret_code);
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
	if (*(data->argv[1]) == '~' && ft_strlen(data->argv[1]) == 1)
	{
		free(data->argv[1]);
		data->argv[1] = get_home_path(data);
		if (cd_builtin_check_valid(data->argv[1]) != 0)
		{
			g_signal_num = 1;
			return (RET_FAIL);
		}
		if (data->argv[1] == 0)
			data->argv[1] = data->init_homepath;
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
		ft_putstr_fd("bfsh: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (errno);
	}
	if (check_dir_file(str) == FILETYPE)
	{
		ft_putstr_fd("bfsh: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Not a directory\n", 2);
		return (ENOTDIR);
	}
	if (access(str, X_OK) == -1)
	{
		ft_putstr_fd("bfsh: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied\n", 2);
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
		make_oldpwd(data);
	else
	{
		free(data->envp[target_idx]);
		if (getcwd(cwd, 4096) == 0)
			inner_function_error("getcwd fail\n");
		target = ft_strjoin(str, cwd);
		data->envp[target_idx] = target;
	}
	return (0);
}
