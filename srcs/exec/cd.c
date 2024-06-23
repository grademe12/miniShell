/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/23 17:18:30 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_builtin(t_data *data)
{
	char	*home;
	
	if (data->argv[2] != 0)
	{
		ft_printf("cd: too many arguments\n");
		ft_errnum(1);
		return (-1);
	}
	home = get_home_path(data);
	if (data->argv[1] == 0)
	{
		if (home == 0)
		{
			ft_printf("cd: HOME not set\n");
			ft_errnum(1);
			return (-1);
		}
		chdir(home);
		free(home);
		ft_errnum(0);
		return (0);
	}
	return(cd_builtin2(data));
}

int	cd_builtin2(t_data *data)
{
	if (access(data->argv[1], F_OK) == -1)
	{
		ft_printf("cd: %s: No such file or directory\n", data->argv[1]);
		ft_errnum(1);
		return (-1);
	}
	if (check_dir_file(data->argv[1]) == FILETYPE)
	{
		ft_printf("cd: %s: Not a directory\n", data->argv[1]);
		ft_errnum(1);
		return (-1);
	}
	if (access(data->argv[1], X_OK == -1)) //stat, errno, 권한 문제와 순서에 대해 고민해보기
	{
		ft_printf("cd: %s: Permission denied\n", data->argv[1]);
		ft_errnum(1);
		return (-1);
	}
	chdir(data->argv[1]);
	ft_errnum(0);
	return (0);
}

int	change_env_pwd(t_data *data)
{
	int		old_pwd;
	int		pwd;
	char	cwd[4096];

	if (getcwd(cwd, 4096) == -1)
		inner_function_error("get cwd fail\n");
	old_pwd = check_dup(data, "OLDPWD=", 6);
}

int	make_oldpwd(t_data *data)
{
	int		i;
	char	*ow;
	char	cwd[4096];

	i = 0;
	if (getcwd(cwd, 4096) == -1)
		inner_function_error("get cwd fail\n");
	ow = ft_strjoin("OLDPWD=", cwd);
	do_export(data, ow, 6);
	return (0);
}

char	*get_home_path(t_data *data)
{
	int		home_index;
	char	*home_path;
	
	home_index = find_unest(data, "HOME=");
	if (home_index == -1)
		return (0);
	home_path = ft_strdup(data->envp[home_index] + 5);
	return (home_path);
}
