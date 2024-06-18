/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:37:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 02:44:00 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	input_red(t_token *cur, int type)
{
	char	*filename;
	int		fd;

	filename = cur->next->token;
	if (filename == 0)
	{
		ft_printf("%s: %s\n", 2, "minishell: ", "syntax error near unexpected token 'newline'");
		return (1);
	}
	if (access(filename, F_OK) == -1)
	{
		perror(errno);
		return (errno);
	}
	fd = open_type(filename, type);
	if (fd == -1)
	{
		perror(errno);
		return (errno);
	}
	red_dup(fd, type);
	return (0);
}

int	open_type(char *filename, int type)
{
	int	fd;

	if (type == INPUT_REDIR)
		fd = open(filename, O_RDONLY, 0644);
	if (type == OUTPUT_REDIR)
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (type == APPEND_REDIR)
		fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (type == HEREDOC)
	{
		
	}
}

int	heredoc_red(t_token *cur)
{
	
}

int	red_dup(int fd, int type)
{
	if (type == INPUT_REDIR)
		if (dup2(fd, STDIN_FILENO) == -1)
			inner_function_error("dup2 error\n");
	if (type == OUTPUT_REDIR || type == APPEND_REDIR)
		if (dup2(fd, STDOUT_FILENO) == -1)
			inner_function_error("dup2 error\n");
	return (0);		
}

