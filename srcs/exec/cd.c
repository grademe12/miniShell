/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 02:20:57 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_builtin(t_data *data)
{
	char	*home;
	int		ret_code;
	
	home = get_home_path(data);
	ret_code = 0;
	if (data->argv[1] == 0)
	{
		if (home == 0)
		{
			ft_printf("cd: HOME not set\n");
			signal_num = 1;
			return (0);
		}
		change_env_pwd(data, "OLDPWD=");
		chdir(home);
		change_env_pwd(data, "PWD=");
		free(home);
		signal_num = 0;
		return (0);
	}
	ret_code = cd_builtin2(data);
	change_env_pwd(data, "PWD=");
	return(ret_code);
}

int	cd_builtin2(t_data *data)
{
	if (*data->argv[1] == '~' && ft_strlen(data->argv[1]) == 1)
	{
		data->argv[1] = get_home_path(data);
		if (data->argv[1] == 0)
			data->argv[1] = data->init_homepath;
	}
	if (access(data->argv[1], F_OK) == -1)
		return (ENOENT);
	if (check_dir_file(data->argv[1]) == FILETYPE)
		return (ENOTDIR);
	if (access(data->argv[1], X_OK) == -1)
		return (EACCES);
	change_env_pwd(data, "OLDPWD=");
	chdir(data->argv[1]);
	signal_num = 0;
	return (0);
}

int	change_env_pwd(t_data *data, char *str) // env의 oldpwd를 최신화 -> chdir이 성공적으로 되기 직전에만 call
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

int	make_oldpwd(t_data *data)
{
	char	*ow;
	char	cwd[4096];

	if (getcwd(cwd, 4096) == 0)
		inner_function_error("get cwd fail\n");
	ow = ft_strjoin("OLDPWD=", cwd);
	do_export(data, ow, 6);
	return (0);
}

char	*get_home_path(t_data *data)
{
	int		home_index;
	char	*home_path;
	
	home_index = find_unset(data, "HOME=");
	if (home_index == -1)
		return (0);
	home_path = ft_strdup(data->envp[home_index] + 5);
	return (home_path);
}
