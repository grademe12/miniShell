/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:43 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/25 06:31:52 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	input_num_pipe(t_data **begin, int np)
{
	t_data	*nownode;

	nownode = *begin;
	while (nownode)
	{
		nownode->num_pipe = np;
		nownode = nownode->next;
	}
}

int	parsing(t_data **begin, char *line)
{
	t_data	*begin_node;
	int		idx;
	int		sq;
	int		dq;
	int		np;

	idx = -1;
	begin_node = NULL;
	sq = 0;
	dq = 0;
	np = 0;
	if (!line[0])
		return (0);
	while (line[++idx])
	{
		if (!check_quote(line[idx], &sq, &dq) && line[idx] == '|')
		{
			np++;
			make_data(&begin_node, line, *begin, idx + 1);
			if (begin_node == 0)
				return (0);
			line = line + idx + 1;
			idx = -1;
		}
	}
	make_data(&begin_node, line, *begin, idx + 1);
	if (begin_node == 0)
		return (0);
	input_num_pipe(&begin_node, np);
	free_data(begin);
	*begin = begin_node;
	return (1);
}
