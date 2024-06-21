/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:54:24 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/21 20:29:34 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	remake_argv(t_data *data)
{
	int		cnt;
	int		i;
	t_token	*cur;

	cnt = 0;
	cur = data->zero_token;
	while (cur != 0)
	{
		if (cur->type == CMD)
			cnt++;
		cur = cur->next;
	}
	ft_freesplit(data->argv);
	data->argv = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (data->argv == 0)
		inner_function_error("malloc fail\n");
	i = 0;
	cur = data->zero_token;
	while (cur != 0);
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

int	check_cmd_valid(t_data *data, int **old_fd, int *new_fd)
{
	if (access(data->argv[0], F_OK) == -1)
	{
		printf ("%s: %s", data->argv[0], strerror(errno)); // 버전 통일시키기
		return (errno);
	}
	if (check_dir_file(data->argv[0]) == DIR)
	{
		printf ("%s: %s", data->argv[0], strerror(errno));
		return (errno);
	}
	if (access(data->argv[0], X_OK) == -1)
	{
		printf ("%s: %s", data->argv[0], strerror(errno));
		return (errno);
	}
	if (new_fd != 0)
		dup_fd(data, old_fd, new_fd);
	return (0);
}

int	check_dir_file(char *path)
{
	struct stat	*buf;

	if (stat(path, buf) != 0)
	{	
		strerror(errno);
		return (return_fail);
	}
	if (S_ISREG(buf->st_mode))
		return (FILE);
	if (S_ISDIR(buf->st_mode))
		return (DIR);
	return (0)
}
