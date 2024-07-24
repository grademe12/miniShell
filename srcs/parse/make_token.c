/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:34:28 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/24 21:23:52 by sanghhan         ###   ########.fr       */
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
	char	*temp;
	int		i;

	begin = NULL;
	i = -1;
	type = CMD;
	while (av[++i])
	{
		temp = ft_strdup(av[i]);
		if (type != CMD)
			nowtoken = new_token_node(temp, type);
		else
		{
			type = get_type(av[i]);
			nowtoken = new_token_node(temp, type);
		}
		type = get_type(av[i]);
		ft_tokenadd_back(&begin, nowtoken);
	}
	return (begin);
}
