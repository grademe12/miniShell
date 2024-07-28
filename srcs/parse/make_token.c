/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:34:28 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/27 15:45:03 by sanghhan         ###   ########.fr       */
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
	nowtoken = NULL;
	i = -1;
	type = CMD;
	while (av[++i])
	{
		temp = ft_strdup(av[i]);
		type = get_type(av[i]);
		if (i > 0 && get_type(av[i - 1]) != CMD)
		{
			if (get_type(av[i]) == CMD)
				nowtoken = new_token_node(temp, FILENAME);
			else
			{
				error_unexpected_token();
				free_token(&begin);
				begin = NULL;
				break ;
			}
		}
		else
			nowtoken = new_token_node(temp, type);
		ft_tokenadd_back(&begin, nowtoken);
	}
	if (begin
		&& (ft_tokenlast(begin)->type != CMD)
		&& (ft_tokenlast(begin)->type != FILENAME))
	{
		error_unexpected_token();
		free_token(&begin);
		begin = NULL;
	}
	return (begin);
}
