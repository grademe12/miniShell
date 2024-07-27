/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:43 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/27 15:43:09 by sanghhan         ###   ########.fr       */
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

int	check_line(char *line)
{
	int	idx;
	int	sq;
	int	dq;
	int	flag;

	idx = -1;
	sq = 0;
	dq = 0;
	while (line[idx++])
	{
		flag = check_quote(line[idx], &sq, &dq);
		if (!flag && (line[idx] == ';' || line[idx] == '\\'))
		{
			if (line[idx] == ';')
				error_unexpected_token();
			if (line[idx] == '\\')
				error_unexpected_token();
			return (0);
		}
	}
	if (sq || dq)
	{
		printf("bfsh: syntax error unterminated quoted string\n");
		g_signal_num = 258;
		return (0);
	}
	return (1);
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
	if (!line[0] || !check_line(line))
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
