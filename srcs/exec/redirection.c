/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:37:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 21:01:28 by woosupar         ###   ########.fr       */
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

int	heredoc_red(t_token *cur)
{
	char	*buf;
	char	*heredoc;
	int		fd;

	heredoc = heredoc_init();
	fd = open(heredoc, O_RDWR | O_CREAT | O_EXCL, 0644);
	if (fd == -1)
		heredoc = multi_heredoc(heredoc);
	buf = get_next_line(0);
	while (ft_strcmp(buf, cur->next->token) != 0)
	{
		write(fd, buf, ft_strlen(buf));
		free(buf);
		buf = get_next_line(0);
	}
	if (red_dup(fd, HEREDOC) == -1)
		return (errno);
	return (0);
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

char	*heredoc_init(void)
{
	char	*doc;

	doc = (char *)malloc(sizeof(ft_strlen("/tmp/doc") + 1));
	if (doc == 0)
		inner_function_error("malloc fail\n");
	ft_strlcpy(doc, "/tmp/doc", ft_strlen("/tmp/doc") + 1);
	return (doc);
}