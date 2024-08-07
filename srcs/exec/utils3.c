/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:17:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/01 14:50:36 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	fd_init(t_data *data)
{
	t_data	*cur;

	cur = data;
	while (cur != 0)
	{
		data->last_in = 0;
		data->last_out = 0;
		cur = cur->next;
	}
}

int	make_oldpwd(t_data *data, char *str)
{
	char	*ow;
	char	cwd[4096];
	int		i;

	if (getcwd(cwd, 4096) == 0)
		inner_function_error("get cwd fail\n");
	ow = ft_strjoin(str, cwd);
	ft_realloc(data);
	i = 0;
	while (data->envp[i] != 0)
		i++;
	data->envp[i] = ow;
	return (0);
}

int	ft_getcwd(t_data *data)
{
	int		pwd_idx;
	char	*pwd;
	char	cwd[4096];

	if (data->pwd != 0)
		free(data->pwd);
	pwd_idx = check_dup(data, "PWD=", 3);
	if (pwd_idx != -1)
	{
		pwd = data->envp[pwd_idx];
		pwd = pwd + 4;
		data->pwd = ft_strdup(pwd);
	}
	else
	{
		getcwd(cwd, 4096);
		data->pwd = ft_strdup(cwd);
	}
	return (0);
}

void	go_to_homepath(t_data *data)
{
	int	check;

	check = chdir(data->init_homepath);
	if (check == 0)
	{
		change_env_pwd(data, "OLDPWD=");
		change_env_pwd(data, "PWD=");
		return ;
	}
	check = chdir("/");
	if (check == 0)
	{
		change_env_pwd(data, "OLDPWD=");
		change_env_pwd(data, "PWD=");
		return ;
	}
	else
		exit(1);
}
