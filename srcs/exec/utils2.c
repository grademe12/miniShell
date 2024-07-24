/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:54:24 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 15:45:21 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	remake_argv(t_data *data)
{
	int		cnt;
	int		i;
	t_token	*cur;

	cnt = get_cmd_cnt(data);
	ft_freesplit(data->argv);
	data->argv = 0;
	data->argv = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (data->argv == 0)
		inner_function_error("malloc fail\n");
	i = 0;
	cur = data->zero_token;
	while (cur != 0)
	{
		if (cur->type == CMD)
		{
			data->argv[i] = cur->token;
			i++;
		}
		cur = cur->next;
	}
	data->argv[i] = 0;
	return (0);
}

int	check_dir_file(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) != 0)
	{	
		strerror(errno);
		return (RET_FAIL);
	}
	if (S_ISREG(buf.st_mode))
		return (FILETYPE);
	if (S_ISDIR(buf.st_mode))
		return (DIR);
	return (0);
}

int	find_equals(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

void	envp_alloc(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
	{
		data->envp[i] = ft_strdup(envp[i]);
		if (data->envp[i] == 0)
			exit (1);
		i++;
	}
	data->envp[i] = 0;
}

int	get_cmd_cnt(t_data *data)
{
	int		cnt;
	t_token	*cur;

	cnt = 0;
	cur = data->zero_token;
	while (cur != 0)
	{
		if (cur->type == CMD)
			cnt++;
		cur = cur->next;
	}
	return (cnt);
}
