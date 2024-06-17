/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/17 22:18:05 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	pid_t	pids[data->num_pipe + 1];
	pid_t	fastest_exit_pid;
	int		old_fd[2];
	int		i;

	i = 0;
	while (i < data->num_pipe + 1)
	{
		make_child(data, pids, i, old_fd);
		i++;
	}
	i = 0;
	fastest_exit_pid = wait(0);
	if (fastest_exit_pid == pids[data->num_pipe])
	{
	}
	while (i < data->num_pipe)
	{
		waitpid(pids[i], 0, 0);
		i++;
	}
}

int	make_child(t_data *data, pid_t *pids, int i, int *old_fd)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{	
		perror("pipe fail");
		exit (1);
	}
	pids[i] = fork();
	if (pids[i] == 0)
		child_working(data, pids, i, old_fd);
	else
	return (0);
}

int	child_working(t_data *data, pid_t *pids, int i, int *old_fd)
{
	if (is_path(data->argv[0]) == -1)
	{
		data->argv[0] = make_path(data->argv, data->envp);
		if (data->argv[0] == 0)
			return (127);
	}
	// 여기까지 완벽함. 첫 번째 토큰을 디렉토리경로/파일 or 디렉토리 이름 으로 통일
	if (access(data->argv[0], F_OK) == -1)
	{
		
		printf ("%s: %s", data->argv[0], strerror(2));
		return (2);
	}
	if (check_dir_file(data->argv[0]) == DIR)
	{
		printf ("%s: %s", data->argv[0], strerror(21));
		return (21);
	}
}
