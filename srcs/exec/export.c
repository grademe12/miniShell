/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:29:54 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/01 15:38:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	export_builtin(t_data *data)
{
	int	i;
	int	eq_index;

	i = 1;
	if (data->argv[1] == 0)
	{
		print_env_declare(data);
		return (0);
	}
	while (data->argv[i] != 0)
	{
		eq_index = find_equals(data->argv[i]);
		if (export_valid_check(data->argv[i], eq_index) == -1)
		{
			export_unset_err(data, "export: ", i);
			i++;
			continue ;
		}
		if (eq_index != -1)
			do_export(data, data->argv[i], eq_index);
		i++;
	}
	if (g_signal_num == 1)
		return (RET_FAIL);
	return (0);
}

int	print_env_declare(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	while (data->envp[i] != 0)
	{
		tmp = ft_strjoin("declare -x ", data->envp[i]);
		ft_printf ("%s\n", tmp);
		free(tmp);
		i++;
	}
	return (0);
}

int	check_dup(t_data *data, char *str, int eq_index)
{
	int	i;

	i = 0;
	while (data->envp[i] != 0)
	{
		if (ft_strncmp(str, data->envp[i], eq_index + 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	do_export(t_data *data, char *str, int eq_index)
{
	int		i;
	char	*dup_str;
	int		dup_index;

	i = 0;
	dup_index = check_dup(data, str, eq_index);
	if (dup_index == -1)
	{
		ft_realloc(data);
		while (data->envp[i] != 0)
			i++;
		dup_str = ft_strdup(str);
		data->envp[i] = dup_str;
		return (0);
	}
	free(data->envp[dup_index]);
	data->envp[dup_index] = str;
	return (0);
}

int	ft_realloc(t_data *data)
{
	char	**ret;
	int		i;

	i = 0;
	while (data->envp[i] != 0)
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 2));
	if (ret == 0)
		inner_function_error("malloc fail\n");
	i = 0;
	while (data->envp[i] != 0)
	{
		ret[i] = data->envp[i];
		i++;
	}
	ret[i] = 0;
	ret[i + 1] = 0;
	free(data->envp);
	data->envp = ret;
	return (0);
}
