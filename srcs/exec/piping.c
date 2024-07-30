/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:47:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 18:39:51 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	piping(t_data *data)
{
	t_data		*phrase;
	int			*new_fd;
	int			*old_fd;
	int			i;

	i = 0;
	phrase = data;
	old_fd = 0;
	while (phrase != 0)
	{
		if (i == data->num_pipe)
			last_child(phrase, i, old_fd);
		else
		{
			new_fd = (int *)malloc(sizeof(int) * 2);
			if (new_fd == 0 || pipe(new_fd) == -1)
				inner_function_error("pipe malloc fail\n");
			make_child(phrase, old_fd, new_fd);
		}
		phrase = phrase->next;
		old_fd = new_fd;
		i++;
	}
	return (0);
}

int	make_child(t_data *data, int *old_fd, int *new_fd)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pid == -1)
		inner_function_error("fork fail\n");
	if (pid == 0)
		child_working(data, old_fd, new_fd);
	else
	{
		if (old_fd != 0)
		{
			close(old_fd[0]);
			free(old_fd);
		}
		close(new_fd[1]);
	}
	return (0);
}

int	child_working(t_data *data, int *old_fd, int *new_fd)
{
	t_token		*cur;

	if (data->argv == 0)
		exit (0);
	signal_child();
	fd_init(data);
	cur = data->zero_token;
	if (cur == 0)
		return (0);
	while (cur != 0)
	{
		if (check_red(data, cur) != 0)
			exit(errno);
		cur = cur->next;
	}
	if (data->last_fd != 0)
	{
		if (dup2(data->last_fd, STDIN_FILENO) == -1)
			inner_function_error("dup2 fail\n");
		close(data->last_fd);
	}
	if (check_cmd_valid(data, old_fd, new_fd) == 127)
		return (127);
	return (0);
}

int	check_cmd_valid(t_data *data, int *old_fd, int *new_fd)
{
	remake_argv(data);
	if (is_path(data->argv[0]) == -1)
	{
		if (check_builtin(data->argv[0]) != NOT_BUILTIN)
			dup_fd(data, old_fd, new_fd);
		data->argv[0] = make_path(data->argv, data->envp);
		if (data->argv[0] == 0)
			return (127);
	}
	if (access(data->argv[0], F_OK) == -1)
		child_err_exit(ENOENT, data->argv[0]);
	if (check_dir_file(data->argv[0]) == DIR)
		child_err_exit(EISDIR, data->argv[0]);
	if (access(data->argv[0], X_OK) == -1)
		child_err_exit(EACCES, data->argv[0]);
	dup_fd(data, old_fd, new_fd);
	return (0);
}

int	dup_fd(t_data *data, int *old_fd, int *new_fd)
{
	if (data->last_fd != 0 && old_fd != 0)
		close(old_fd[0]);
	else if (old_fd != 0)
	{
		if (dup2(old_fd[0], STDIN_FILENO) == -1)
			child_err_exit(errno, data->argv[0]);
		close(old_fd[0]);
	}
	if (new_fd != 0)
	{
		close(new_fd[0]);
		if (dup2(new_fd[1], STDOUT_FILENO) == -1)
			child_err_exit(errno, data->argv[0]);
		close(new_fd[1]);
	}
	child_exec(data);
	return (0);
}
