/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:36:22 by sanghhan          #+#    #+#             */
/*   Updated: 2024/06/15 18:40:08 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_node	*make_node(char *line, size_t start, size_t end)
{
	size_t	start_i;
	size_t	end_i;
	int		single_quote;
	int		double_quote;

	start_i = start;
	end_i = start;
	single_quote = 0;
	double_quote = 0;
	while (end_i < end)
	{
		check_quote(line, &end_i, &single_quote, &double_quote);
	}
}

t_node	*addnode_back(t_node *begin, t_node *node)
{
	t_node	*tmp;

	if (!begin)
		return (node);
	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (begin);
}
