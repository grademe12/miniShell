/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:37:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/20 13:53:32 by woosupar         ###   ########.fr       */
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
	if (type == INPUT_REDIR)
		if (dup2(fd, STDIN_FILENO) == -1)
			return (-1);
	if (type == OUTPUT_REDIR || type == APPEND_REDIR)
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (-1);
	if (type == HEREDOC)
		if (dup2(fd, STDIN_FILENO) == -1)
			return (-1);
	return (0);		
}
