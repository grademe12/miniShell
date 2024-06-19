/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:12:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 13:15:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*make_path(char **argv, char **envp)
{
	int		i;
	char	**path_split;
	char	*tmp;

	i = -1;
	while (envp[++i] != 0)
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
	if (envp[i] == 0)
	{
		printf ("%s: %s\n", argv[0], "command not found");
		return (127);
	}
	path_split = ft_split(envp[i] + 5, ':');
	i = -1;
	while (path_split[++i] != 0)
	{
		tmp = ft_strjoin_pipe(path_split[i], argv[0]);
		if (access(tmp, F_OK) && check_dir_file(tmp) == FILE)
			break ;
		free(tmp);
	}
	if (cannot_find(path_split, argv) == 127)
		return (127);
	return (tmp);
}

int	cannot_find(char **path_split, char **argv)
{
	if (path_split == 0)
	{
		printf ("%s: %s\n", argv[0], "command not found");
		ft_freesplit(path_split);
		return (127);
	}
	ft_freesplit(path_split);
	free(argv[0]);
	return (0);
}
