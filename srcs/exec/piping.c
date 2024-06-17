/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/18 03:11:51 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	pid_t	fastest_exit_pid;
	int		*old_fd;
	int		i;

	i = 0;
	while (data != 0)
	{
		make_child(data, i, old_fd);
		data = data->next;
	}
	i = 0;
	fastest_exit_pid = wait(0);
	if (fastest_exit_pid == pids[data->num_pipe])
	{
	}
	while (i < data->num_pipe)
	{
		waitpid(data->pids[i], 0, 0);
		i++;
	}
}

int	make_child(t_data *data, int i, int *old_fd)
{
	int	new_fd[2];

	if (pipe(fd) == -1)
	{	
		perror("pipe fail");
		exit (1);
	}
	pids[i] = fork();
	if (pids[i] == 0)
		child_working(data, i, old_fd, new_fd);
	else
	return (0);
}

int	child_working(t_data *data, int i, int *old_fd, int *new_fd)
{
	if (is_path(data->argv[0]) == -1)
	{
		data->argv[0] = make_path(data->argv, data->envp);
		free(data->zero_token->token);
		data->zero_token->token = data->argv[0]; // 필요 없을지도
		if (data->argv[0] == 0)
			return (127);
	}
	// 여기까지 완벽함. 첫 번째 토큰을 디렉토리경로/파일 or 디렉토리 이름 으로 통일
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
		printf ("%s: %s", dat->argv[0], strerror(errno));
		return (errno);
	}
	child_working2(data, i, old_fd, new_fd);
	return (0);
}

int	child_working2(t_data *data, int i, int *old_fd, int *new_fd)
{
	
}