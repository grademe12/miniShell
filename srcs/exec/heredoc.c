/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:21:06 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/20 13:53:24 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*multi_heredoc(char *str)
{
	char	*ret;

	ret = ft_strjoin(str, "doc");
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
