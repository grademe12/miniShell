/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/22 17:48:10 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_builtin(t_data *data)
{
	char	*home;
	
	home = get_home_path(data);
	if (data->argv[1] == 0)
	{
		if (home == 0)
		{
			ft_printf("cd: HOME not set\n");
			signal_num = 1;
			return (-1);
		}
		change_env_pwd(data);
		chdir(home);
		free(home);
		signal_num = 0;
		return (0);
	}
	return(cd_builtin2(data));
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
	{
		ft_printf("cd: %s: No such file or directory\n", data->argv[1]); //strerror(errno);
		signal_num = 1;
		return (-1);
	}
	if (check_dir_file(data->argv[1]) == FILETYPE)
	{
		ft_printf("cd: %s: Not a directory\n", data->argv[1]);
		signal_num = 1;
		return (-1);
	}
	if (access(data->argv[1], X_OK == -1)) //stat, errno, 권한 문제와 순서에 대해 고민해보기
	{
		ft_printf("cd: %s: Permission denied\n", data->argv[1]);
		signal_num = 1;
		return (-1);
	}
	change_env_pwd(data);
	chdir(data->argv[1]);
	signal_num = 0;
	return (0);
}

int	change_env_pwd(t_data *data) // env의 oldpwd를 최신화 -> chdir이 성공적으로 되기 직전에만 call
{
	int		old_pwd_idx;
	char	*old_pwd;
	char	cwd[4096];
	
	old_pwd_idx = check_dup(data, "OLDPWD=", 6);
	if (old_pwd_idx == -1)
		make_oldpwd(data);
	else
	{
		free(data->envp[old_pwd_idx]);
		if (getcwd(cwd, 4096) == 0)
			inner_function_error("getcwd fail\n");
		old_pwd = ft_strjoin("OLDPWD=", cwd);
		data->envp[old_pwd_idx] = old_pwd;
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
