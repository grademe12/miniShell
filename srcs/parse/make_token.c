/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:34:28 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/16 19:06:50 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*ft_tokenlast(t_token *token)
{
	if (token == 0)
		return (token);
	while (token->next != 0)
		token = token->next;
	return (token);
}

void	ft_tokenadd_back(t_token **begin, t_token *token)
{
	if (begin == 0)
		return ;
	if (*begin == 0)
		*begin = token;
	else
		ft_tokenlast(*begin)->next = token;
}

t_type	get_type(char *c)
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

t_token	*make_token(char **av)
{
	t_token	*begin;
	t_token	*nowtoken;
	t_type	type;

	begin = NULL;
	while (*av)
	{
		type = get_type(*av);
		nowtoken = new_token_node(*av, type);
		ft_tokenadd_back(&begin, nowtoken);
		av++;
	}
	return (begin);
}
