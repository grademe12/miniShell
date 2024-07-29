/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:34:28 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 05:20:39 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_token	*ft_tokenlast(t_token *token)
{
	if (token == 0)
		return (token);
	while (token->next != 0)
		token = token->next;
	return (token);
}

static void	ft_tokenadd_back(t_token **begin, t_token *token)
{
	if (begin == 0)
		return ;
	if (*begin == 0)
		*begin = token;
	else
		ft_tokenlast(*begin)->next = token;
}

static t_type	get_type(char *c)
{
	if (!ft_strcmp(c, ">"))
		return (OUTPUT_REDIR);
	else if (!ft_strcmp(c, "<"))
		return (INPUT_REDIR);
	else if (!ft_strcmp(c, ">>"))
		return (APPEND_REDIR);
	else if (!ft_strcmp(c, "<<"))
		return (HEREDOC);
	else
		return (CMD);
}

static t_token	*token_error(t_token **begin)
{
	error(UNEXP_TOKEN_MSG, UNEXP_TOKEN);
	free_token(begin);
	*begin = NULL;
	return (NULL);
}

t_token	*make_token(char **av)
{
	t_token	*begin;
	t_token	*nowtoken;
	t_type	type;
	char	*temp;
	int		i;

	begin = NULL;
	nowtoken = NULL;
	i = -1;
	while (av[++i])
	{
		temp = ck_malloc(ft_strdup(av[i]));
		type = get_type(av[i]);
		if (i > 0 && get_type(av[i - 1]) != CMD && get_type(av[i]) != CMD)
			return (token_error(&begin));
		else
			nowtoken = new_token_node(temp, type);
		ft_tokenadd_back(&begin, nowtoken);
	}
	if (begin && nowtoken->type != CMD && nowtoken->type != FILENAME)
		return (token_error(&begin));
	return (begin);
}
