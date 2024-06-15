/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:43 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/13 23:20:37 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_quote(char *line, size_t *i, int *single_quote, int *double_quote)
{
	if (*single_quote || *double_quote)
	{
		if (line[*i] == '\'' && *single_quote && !*double_quote)
		{
			*single_quote = !*single_quote;
			return (0);
		}
		if (line[*i] == '\"' && *double_quote && !*single_quote)
		{
			*double_quote = !*double_quote;
			return (0);
		}
		*i += 1;
		return (1);
	}
	if (line[*i] == '\'' || line[*i] == '\"')
	{
		if (line[*i] == '\"')
			*double_quote = !*double_quote;
		else if (line[*i] == '\'')
			*single_quote = !*single_quote;
		*i += 1;
	}
	return (0);
}

int	meet_redir(char *line, size_t *start, size_t *end, t_node *begin)
{
	t_node	*node;

	node = make_node(line, *start, *end);
	if (!node)
		return (0);
	addnode_back(begin, node);
	*start = *end;
	while (line[*end] != ' ')
		*end += 1;
	node = make_node(line, *start, *end);
	if (!node)
		return (0);
	addnode_back(begin, node);
	return (1);
}

int	meet_pipe(char *line, size_t *start, size_t *end, t_node *begin)
{
	t_node	*node;

	if (make_node(line, *start, *end))
		return (0);
	*start = *end;
	*end += 1;
	make_node(line, *start, *end);
	end += 1;
	return (1);
}

t_node	*make_list(char *line, t_node *begin)
{
	size_t	start_i;
	size_t	end_i;
	int		single_quote;
	int		double_quote;

	start_i = 0;
	end_i = 0;
	single_quote = 0;
	double_quote = 0;
	while (line[end_i])
	{	
		if (check_quote(line, &end_i, &single_quote, &double_quote))
			continue ;
		else if (line[end_i] == '|' || line[end_i + 1] == '\0')
			meet_pipe(line, &start_i, &end_i, begin);
		else if (line[end_i] == '<' || line[end_i] == '>'\
				|| line[end_i] == '<<' || line[end_i] == '>>')
			meet_redir(line, &start_i, &end_i, begin);
		end_i++;
	}
}

t_node	*parse(void)
{
	t_node	*begin;
	char	*line;

	line = readline("minishell $");
	if (!line)
		return (NULL);
	return (begin);
}
