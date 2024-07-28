/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:21:06 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/28 12:45:31 by woosupar         ###   ########.fr       */
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

	signal(SIGTERM, SIG_DFL);
	sig_print_off();
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
	free(doc);
	return (0);
}

int	heredoc_red(t_data *data, t_token *cur)
{
	char	*heredoc;
	int		fd;

	heredoc = heredoc_init();
	fd = open(heredoc, O_RDWR | O_CREAT | O_EXCL, 0644);
	while (fd == -1)
	{
		heredoc = multi_heredoc(heredoc);
		fd = open(heredoc, O_RDWR | O_CREAT | O_EXCL, 0644);
	}
	make_temp_doc(fd, cur);
	fd = open(heredoc, O_RDONLY);
	if (fd == -1)
		exit(1);
	if (data->last_fd != 0)
		close(data->last_fd);
	data->last_fd = fd;
	free(heredoc);
	return (0);
}

int	make_temp_doc(int fd, t_token *cur)
{
	char	*buf;
	char	*limit;

	limit = ft_strjoin(cur->next->token, "\n");
	while (1)
	{
		ft_putstr_fd("> ", 1);
		buf = get_next_line(0);
		if (buf == 0)
			break ;
		if (ft_strcmp(buf, limit) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		free(buf);
	}
	close(fd);
	free(buf);
	free(limit);
	return (0);
}
