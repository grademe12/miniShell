/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:49:38 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/13 13:25:47 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	check_quote(char c, int *single_quote, int *double_quote)
{
	if (*single_quote || *double_quote || c == '\'' || c == '\"')
	{
		if (c == '\'' && *single_quote && !*double_quote)
			*single_quote = !*single_quote;
		if (c == '\"' && *double_quote && !*single_quote)
			*double_quote = !*double_quote;
		return (1);
	}
	return (0);
}

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	check_rdi(char const *str)
{
	if (str[0] == '>')
	{
		if (str[1] && str[1] == '>')
			return (2);
		return (1);
	}
	else if (str[0] == '<')
	{
		if (str[1] && str[1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

static int	check_rdi(char const *str)
{
	if (str[0] == '>')
	{
		if (str[1] && str[1] == '>')
			return (2);
		return (1);
	}
	else if (str[0] == '<')
	{
		if (str[1] && str[1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

static int	get_words_len(char const *str, char sep)
{
	size_t	ind;
	int		s_quote;
	int		d_quote;

	ind = check_rdi(str);
	s_quote = 0;
	d_quote = 0;
	if (ind)
		return (ind);
	while (str[ind] \
		&& (check_quote(str[ind], &s_quote, &d_quote) || !is_sep(str[ind])) \
		&& (str[ind] != '|' && str[ind] != '>' && str[ind] != '<'))
		ind++ ;
	return (ind);
}

static int	count_words(char const *str, char sep)
{
	size_t	ind;
	size_t	cnt;
	int		single_quote;
	int		double_quote;
	int		temp;

	ind = -1;
	cnt = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[++ind])
	{
		temp = (single_quote || double_quote);
		check_quote(str[ind], &single_quote, &double_quote);
		if (!is_sep(str[ind], sep) || single_quote || double_quote)
		{
			if (ind == 0)
				cnt++;
			else if (is_sep(str[ind - 1]) && !temp)
				cnt++;
			else if (str[ind] == '|')
				cnt++;
			else if (str[ind] == '>' || str[ind] == '<')
			{
				if (check_rdi(&str[ind]))
					ind++;
				cnt++;
			}
		}
	}
	return (cnt);
}

char	**mns_split(char const *s)
{
	char	**retarr;
	size_t	word_cnt;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (0);
	word_cnt = count_words(s);
	printf("word_cnt : [%ld]\n", word_cnt);
	retarr = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (!retarr)
		exit_error();
	i = 0;
	while (i < word_cnt)
	{
		while (is_sep(*s, sep))
			s++;
		word_len = get_words_len(s, sep);
		retarr[i] = ft_substr(s, 0, word_len);
		if (!retarr[i])
			exit_error();
		s += word_len;
		i++;
	}
	retarr[i] = NULL;
	return (retarr);
}
