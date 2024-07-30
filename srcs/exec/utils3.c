/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:17:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 13:34:09 by woosupar         ###   ########.fr       */
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
		data->last_fd = 0;
		cur = cur->next;
	}
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
