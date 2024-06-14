/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/15 03:16:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	pid_t	pids[data->num_pipe];
	int		i;

	i = 0;
	while (i < data->num_pipe)
	{
		make_child(data, pids, i);
		i++;
	}
}

int	make_child(t_data *data, pid_t *pids, int i)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{	
		perror("pipe fail");
		exit (1);
	}
	pids[i] = fork();
	if (pids[i] == 0)
		child_working(data->argv, pids, i);
	else
		waitpid(pids[i], 0, 0);
	return (0);
}

int	child_working(char **argv, pid_t *pids, int i)
{
	if (check_dir_file(argv[0]) == DIR)
	{
		printf ("%s: %s", argv[0], strerror(126));
		return (0);
	}
}