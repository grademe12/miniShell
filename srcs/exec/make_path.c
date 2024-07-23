/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:12:21 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 04:20:48 by woosupar         ###   ########.fr       */
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
		signal_num = 127;
		return (0);
	}
	path_split = ft_split(envp[i] + 5, ':');
	i = -1;
	while (path_split[++i] != 0)
	{
		tmp = ft_strjoin_pipe(path_split[i], argv[0]);
		if (access(tmp, F_OK) == 0 && check_dir_file(tmp) == FILETYPE)
			break ;
		free(tmp);
	}
	if (cannot_find(path_split, argv, i) == 127)
		return (0);
	return (tmp);
}

int	cannot_find(char **path_split, char **argv, int i)
{
	if ((path_split == 0 || path_split[i] == 0) && \
		check_builtin(argv[0]) == -1)
	{
		printf ("minishell: %s: %s\n", argv[0], "command not found");
		ft_freesplit(path_split);
		signal_num = 127;
		return (127);
	}
	ft_freesplit(path_split);
	free(argv[0]);
	return (0);
}
