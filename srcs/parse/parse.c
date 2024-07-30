/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:43 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 19:10:33 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	input_num_pipe(t_data **begin)
{
	t_data	*nownode;
	int		np;

	nownode = *begin;
	np = -1;
	while (nownode)
	{
		np++;
		nownode = nownode->next;
	}
	nownode = *begin;
	while (nownode)
	{
		nownode->num_pipe = np;
		nownode = nownode->next;
	}
}

static int	check_line(char *line)
{
	int	idx;
	int	flag;

	idx = -1;
	flag = 0;
	while (line[idx++])
	{
		flag = check_quote(line, idx);
		if (!flag && (line[idx] == ';' || line[idx] == '\\'))
		{
			if (line[idx] == ';' || line[idx] == '\\')
				error(UNEXP_TOKEN_MSG, UNEXP_TOKEN);
			return (0);
		}
	}
	if (flag)
	{
		error(UNTERM_QUOTE, UNEXP_TOKEN);
		return (0);
	}
	return (1);
}

int	parsing(t_data **begin, char *line)
{
	t_data	*begin_node;
	int		idx;
	int		start;

	idx = -1;
	start = 0;
	begin_node = NULL;
	if (!line || !line[0] || !check_line(line))
		return (0);
	while (line[++idx])
	{
		if (!check_quote(line, idx) && line[idx] == '|')
		{
			if (!make_data(&begin_node, line + start, *begin, idx - start))
				return (0);
			start = idx + 1;
		}
	}
	if (!make_data(&begin_node, line + start, *begin, idx - start))
		return (0);
	input_num_pipe(&begin_node);
	free_data(begin);
	*begin = begin_node;
	return (1);
}
