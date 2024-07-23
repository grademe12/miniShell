/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:37:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 23:18:58 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	input_red(t_token *cur, int type)
{
	char	*filename;
	int		fd;

	filename = cur->next->token; // 유효하지 않은 이름일때 오류 어떻게 판별? 리다이렉션 syntax체크 필요
	if (filename == 0 || check_dir_file(filename) == DIR)
	{
		if (filename == 0)
			ft_printf("%s: %s\n", "bfsh: ", \
			"syntax error near unexpected token");
		else
			ft_printf("%s: %s\n", "bfsh: ", "is a directory");
		signal_num = 1;
		return (signal_num);
	}
	if (type == INPUT_REDIR && access(filename, F_OK) == -1)
		return (errno);
	if (access(filename, F_OK) == 0 && access(filename, W_OK) == -1)
		return (errno);
	fd = open_type(filename, type);
	if (fd == -1)
		return (errno);
	if (red_dup(fd, type) == -1)
		return (errno);
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
	int	temp_fd;
	
	err = 0;
	if (type == INPUT_REDIR || type == HEREDOC)
	{	
		temp_fd = dup(STDIN_FILENO);
		err = dup2(fd, temp_fd)
		close(temp_fd);
	if (type == OUTPUT_REDIR || type == APPEND_REDIR)
	{
		temp_fd = dup(STDOUT_FILENO);
		err = dup2(fd, temp_fd);
		close(temp_fd); // 문제 될 경우가 있을지 잘 모르겠음
	}
	if (err == -1)
		inner_function_error("dup2 error\n");
	return (0);		
}

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
