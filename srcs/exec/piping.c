/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/15 16:29:26 by woosupar         ###   ########.fr       */
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
	i = 0;
	while (i < data->num_pipe)
	{
		waitpid(pids[i], 0, 0);
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
	return (0);
}

int	child_working(char **argv, pid_t *pids, int i)
{
	if (check_dir_file(argv[0]) == DIR)
	{
		printf ("%s: %s", argv[0], strerror(21));
		return (21);
	}
	if (access(argv[0], X_OK) == 0)
	{
		//다음 토큰이 리디렉션인지 확인
		// 리디렉션이면 다음 토큰은 파일명
		//아니라면, 다음 토큰이 옵션인지 확인
	}
	else
	{
		//argv[0]을 env PATH 에서 찾아서 실행 가능한지 확인
	}
}
