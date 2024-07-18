/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:21:06 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/18 21:42:22 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*multi_heredoc(char *str)
{
	char	*ret;

	ret = ft_strjoin(str, "doc");
	free(str);
	if (ret == 0)
		inner_function_error("malloc fail\n");
	return (ret);
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

int	rm_heredoc(void)
{
	char	*doc;

	doc = heredoc_init();
	while (access(doc, F_OK) == 0)
	{
		unlink(doc);
		doc = multi_heredoc(doc);
	}
	return (0);
}

int	heredoc_red(t_token *cur)
{
	char	*buf;
	char	*heredoc;
	int		fd;

	heredoc = heredoc_init();
	fd = open(heredoc, O_RDWR | O_CREAT | O_EXCL, 0644);
	while (fd == -1)
	{
		heredoc = multi_heredoc(heredoc);
		fd = open(heredoc, O_RDWR | O_CREAT | O_EXCL, 0644);
	}
	free(heredoc);
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
