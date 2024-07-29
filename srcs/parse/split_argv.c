/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:49:38 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 02:11:18 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_rdi(char const *str, size_t idx)
{
	if (str[idx] == '>')
	{
		if (str[idx + 1] == '>')
			return (2);
		return (1);
	}
	else if (str[idx] == '<')
	{
		if (str[idx + 1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

static int	is_new_word(const char *str, size_t i)
{
	int	q_flag;
	int	prev_q_flag;
	int	prev_token_flag;

	if (i == 0 && !ft_isspace(str[i]))
		return (1);
	else if (i > 0)
	{
		q_flag = check_quote(str, i);
		prev_q_flag = check_quote(str, i - 1);
		prev_token_flag = (ft_isspace(str[i - 1]) || check_rdi(str, i - 1));
		if (q_flag && !prev_q_flag && prev_token_flag)
			return (1);
		if (!q_flag && !ft_isspace(str[i]) && prev_token_flag)
			return (1);
	}
	return (0);
}

static int	get_words_len(char const *str)
{
	size_t	i;
	int		sq;
	int		dq;

	i = check_rdi(str, 0);
	sq = 0;
	dq = 0;
	if (i)
		return (i);
	while (str[i] && (check_quote(str, i) || \
		(!ft_isspace(str[i]) && !check_rdi(str, i))))
		i++ ;
	return (i);
}

static int	count_words(char const *str)
{
	size_t	i;
	size_t	cnt;
	int		temp;
	int		q_flag;

	i = -1;
	cnt = 0;
	while (str[++i])
	{
		temp = is_new_word(str, i);
		q_flag = check_quote(str, i);
		if ((!q_flag && (str[i] == '>' || str[i] == '<')))
		{
			i += check_rdi(str, i) - 1;
			cnt++;
		}
		else if (temp)
			cnt++;
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
	retarr = (char **)ck_malloc(ft_calloc((word_cnt + 1), sizeof(char *)));
	i = 0;
	while (i < word_cnt)
	{
		while (*s == ' ')
			s++;
		word_len = get_words_len(s);
		retarr[i] = ck_malloc(ft_substr(s, 0, word_len));
		s += word_len;
		i++;
	}
	retarr[i] = NULL;
	return (retarr);
}
