/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:49:38 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/26 20:27:30 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

static int	check_rdi(char const *str)
{
	int	i;

	i = 0;
	if (str[0] == '>')
	{
		i++;
		if (str[i] == '>')
			i++;
		return (i);
	}
	else if (str[0] == '<')
	{
		i++;
		if (str[i] == '<')
			i++;
		return (i);
	}
	return (i);
}

static int	is_new_word(const char *str, size_t i, int sq, int dq)
{
	int	ret;

	ret = ((i > 0) && \
			(!(sq || dq) && \
			(ft_isspace(str[i - 1]) || check_rdi(&str[i - 1]))));
	return (ret);
}

static int	get_words_len(char const *str)
{
	size_t	i;
	int		sq;
	int		dq;

	i = check_rdi(str);
	sq = 0;
	dq = 0;
	if (i)
		return (i);
	while (str[i] && (check_quote(str[i], &sq, &dq) || \
		(str[i] != ' ' && str[i] != '>' && str[i] != '<')))
		i++ ;
	return (i);
}

static int	count_words(char const *str)
{
	size_t	i;
	size_t	cnt;
	int		sq;
	int		dq;
	int		temp;

	i = -1;
	cnt = 0;
	sq = 0;
	dq = 0;
	while (str[++i])
	{
		temp = is_new_word(str, i, sq, dq);
		if (check_quote(str[i], &sq, &dq) || str[i] != ' ')
		{
			if ((!(sq || dq) && (str[i] == '>' || str[i] == '<')))
			{
				i += check_rdi(&str[i]) - 1;
				cnt++;
			}
			else if (i == 0 || temp)
				cnt++;
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
	if (word_cnt == 0)
		return (NULL);
	retarr = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (!retarr)
		exit_error();
	i = 0;
	while (i < word_cnt)
	{
		while (*s == ' ')
			s++;
		word_len = get_words_len(s);
		retarr[i] = ft_substr(s, 0, word_len);
		if (!retarr[i])
			exit_error();
		s += word_len;
		i++;
	}
	retarr[i] = NULL;
	return (retarr);
}
