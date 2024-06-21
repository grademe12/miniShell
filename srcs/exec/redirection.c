/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:37:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/21 19:10:23 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	input_red(t_token *cur, int type)
{
	char	*filename;
	int		fd;

	filename = cur->next->token; // 유효하지 않은 이름일때 오류 어떻게 판별?
	if (filename == 0)
	{
		ft_printf("%s: %s\n", "minishell: ", \
		"syntax error near unexpected token");
		return (1);
	}
	if (type == INPUT_REDIR && access(filename, F_OK) == -1)
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
	
	if (type == INPUT_REDIR)
		err = dup2(fd, STDIN_FILENO);
	if (type == OUTPUT_REDIR || type == APPEND_REDIR)
		err = dup2(fd, STDOUT_FILENO);
	if (type == HEREDOC)
		err = dup2(fd, STDIN_FILENO);
	if (err = -1)
	{
		errnum(9);
		exit(9);
	}
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
	return (0);
}
