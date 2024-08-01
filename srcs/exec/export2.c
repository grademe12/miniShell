/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:19:56 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/01 17:40:14 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	export_valid_check(char *str, int eq_index)
{
	int	i;

	i = 0;
	if (eq_index == 0 || ft_isalpha(str[0]) == 0)
		return (-1);
	while (eq_index == -1 && str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < eq_index)
	{
		if (ft_isalnum(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

char	*tmp_filename(char *filename)
{
	int		i;
	int		last_s;
	char	*ret;

	i = 0;
	last_s = 0;
	while (filename[i] != '\0')
	{
		if (filename[i] == '/')
			last_s = i;
		i++;
	}
	ret = (char *)malloc(4096);
	if (ret == 0)
		exit(1);
	ft_strlcpy(ret, filename, last_s + 1);
	return (ret);
}

int	out_red_valid_check(char *filename)
{
	char	*path;

	path = tmp_filename(filename);
	if (access(path, F_OK) == -1)
	{
		err_print(filename, ENOENT);
		return (ENOENT);
	}
	if (check_dir_file(path) == FILETYPE)
	{
		err_print(filename, ENOTDIR);
		return (ENOTDIR);
	}
	if (access(path, W_OK) == -1)
	{
		err_print(filename, EACCES);
		return (EACCES);
	}
	free(path);
	return (0);
}
