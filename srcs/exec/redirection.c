/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:37:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/27 11:32:57 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_red(t_data *data, t_token *cur)
{
	if (cur->type == INPUT_REDIR)
		return (input_red(cur, INPUT_REDIR));
	if (cur->type == OUTPUT_REDIR)
		return (input_red(cur, OUTPUT_REDIR));
	if (cur->type == APPEND_REDIR)
		return (input_red(cur, APPEND_REDIR));
	if (cur->type == HEREDOC)
		return (heredoc_red(cur));
	(void)data;
	return (0);
}

int	input_red(t_token *cur, int type)
{
	char	*filename;
	int		err;
	int		fd;

	err = 0;
	if (cur->next == 0)
		return (RET_FAIL);
	filename = cur->next->token;
	err = input_red_check_valid(filename, type);
	if (err != 0)
	{
		g_signal_num = 1;
		return (err);
	}
	fd = open_type(filename, type);
	if (fd == -1)
	{
		g_signal_num = 1;
		return (errno);
	}
	if (red_dup(fd, type) == -1)
		return (RET_FAIL);
	return (0);
}

int	input_red_check_valid(char *filename, int type)
{
	if (check_dir_file(filename) == DIR)
	{
		err_print(filename, EISDIR);
		return (RET_FAIL);
	}
	if (type == INPUT_REDIR && access(filename, F_OK) == -1)
	{
		err_print(filename, errno);
		return (ENOENT);
	}
	if (access(filename, F_OK) == 0 && access(filename, W_OK) == -1)
	{
		err_print(filename, errno);
		return (EACCES);
	}
	return (0);
}

int	open_type(char *filename, int type)
{
	int	fd;

	fd = 0;
	if (type == INPUT_REDIR)
		fd = open(filename, O_RDONLY, 0644);
	if (type == OUTPUT_REDIR)
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (type == APPEND_REDIR)
		fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	red_dup(int fd, int type)
{
	int	err;

	err = 0;
	if (type == INPUT_REDIR || type == HEREDOC)
	{
		err = dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (type == OUTPUT_REDIR || type == APPEND_REDIR)
	{
		err = dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (err == -1)
	{
		g_signal_num = 1;
		inner_function_error("dup2 error\n");
	}
	return (0);
}
