/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:48:16 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 15:40:27 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	unset_builtin(t_data *data) // = 있을때 오류나게 수정하기
{
	int	i;
	int	unset_index;

	i = 1;
	while (data->argv[i] != 0)
	{
		if (ft_strchr(data->argv[i], '=') != 0)
		{	
			export_unset_err(data, "unset: ", i);
			return (RET_FAIL);
		}
		unset_index = find_unset(data, data->argv[i]);
		if (unset_index != -1)
			pull_envp(data, unset_index);
		i++;
	}
	remake_envp(data);
	return (0);
}

int	pull_envp(t_data *data, int idx)
{
	free(data->envp[idx]);
	while (data->envp[idx + 1] != 0)
	{
		data->envp[idx] = data->envp[idx + 1];
		idx++;
	}
	free(data->envp[idx]);
	data->envp[idx] = 0;
	return (0);
}

int	find_unset(t_data *data, char *target)
{
	int	i;

	i = 0;
	while (data->envp[i] != 0)
	{
		if (ft_strncmp(target, data->envp[i], ft_strlen(target)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	remake_envp(t_data *data)
{
	char	**ret;
	int		i;

	i = 0;
	while (data->envp[i] != 0)
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (ret == 0)
		inner_function_error("malloc fail\n");
	i = 0;
	while (data->envp[i] != 0)
	{
		ret[i] = data->envp[i];
		i++;
	}
	ret[i] = 0;
	free(data->envp);
	data->envp = ret;
	return (0);
}

int	export_unset_err(t_data *data, char *str, int i)
{
	ft_putstr_fd("bfsh: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(data->argv[i], 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	g_signal_num = 1;
	return (0);
}
