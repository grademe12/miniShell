/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:37:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/01 17:40:33 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_red(t_data *data, t_token *cur)
{
	if (cur->type == INPUT_REDIR)
		return (input_red(data, cur, INPUT_REDIR));
	if (cur->type == OUTPUT_REDIR)
		return (input_red(data, cur, OUTPUT_REDIR));
	if (cur->type == APPEND_REDIR)
		return (input_red(data, cur, APPEND_REDIR));
	if (cur->type == HEREDOC)
		return (heredoc_red(data, cur));
	(void)data;
	return (0);
}

int	input_red(t_data *data, t_token *cur, int type)
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
	if (red_dup(data, fd, type) == -1)
		return (RET_FAIL);
	return (0);
}

int	input_red_check_valid(char *filename, int type)
{
	if (type == OUTPUT_REDIR || type == APPEND_REDIR)
		return (out_red_valid_check(filename));
	if (access(filename, F_OK) == -1)
	{
		err_print(filename, ENOENT);
		return (ENOENT);
	}
	if (check_dir_file(filename) == DIR)
	{
		err_print(filename, EISDIR);
		return (RET_FAIL);
	}
	if (access(filename, W_OK) == -1)
	{
		err_print(filename, EACCES);
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
	if (fd == -1)
		err_print(filename, errno);
	return (fd);
}

int	red_dup(t_data *data, int fd, int type)
{
	int	err;

	err = 0;
	if (type == INPUT_REDIR)
	{
		if (data->last_in != 0)
			close(data->last_in);
		data->last_in = fd;
	}
	if (type == OUTPUT_REDIR || type == APPEND_REDIR)
	{
		if (data->last_out != 0)
			close(data->last_out);
		data->last_out = fd;
	}
	if (err == -1)
	{
		g_signal_num = 1;
		inner_function_error("dup2 error in\n");
	}
	return (0);
}
