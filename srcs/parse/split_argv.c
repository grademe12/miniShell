/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:49:38 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/07 18:17:19 by sanghhan         ###   ########.fr       */
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

static int	get_words_len(char const *str, char sep)
{
	size_t	ind;
	int		single_quote;
	int		double_quote;

	ind = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[ind] && (check_quote(str[ind], &single_quote, &double_quote) \
			|| !is_sep(str[ind], sep)))
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

	ind = 0;
	cnt = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[ind])
	{
		temp = (single_quote || double_quote);
		check_quote(str[ind], &single_quote, &double_quote);
		if (!is_sep(str[ind], sep) || single_quote || double_quote)
		{
			if (ind == 0)
				cnt++;
			else if (is_sep(str[ind - 1], sep) && !temp)
				cnt++;
		}
		ind++;
	}
	return (cnt);
}

char	**mns_split(char const *s, char sep)
{
	char	**retarr;
	size_t	word_cnt;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (0);
	word_cnt = count_words(s, sep);
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
