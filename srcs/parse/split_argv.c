/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:49:38 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/07 16:47:15 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_sep(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

static int	get_words_len(char const *str)
{
	size_t	ind;
	int		single_quote;
	int		double_quote;

	ind = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[ind] && (check_quote(str[ind], &single_quote, &double_quote) \
			|| !is_sep(str[ind])))
		ind++ ;
	return (ind);
}

static int	count_words(char const *str)
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
		if (!is_sep(str[ind]) || single_quote || double_quote)
		{
			if (ind == 0)
				cnt++;
			else if (is_sep(str[ind - 1]) && !temp)
				cnt++;
		}
		ind++;
	}
	return (cnt);
}

char	**ft_split(char const *s)
{
	char	**retarr;
	size_t	word_cnt;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (0);
	word_cnt = count_words(s);
	retarr = (char **)malloc((word_cnt + 1) * sizeof(char *));
	if (!retarr)
		exit_error();
	i = 0;
	while (i < word_cnt)
	{
		while (is_sep(*s))
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

t_type	get_type(char *c)
{
	if (!ft_strcmp(c, ">"))
		return (OUTPUT_REDIR);
	if (!ft_strcmp(c, "<"))
		return (INPUT_REDIR);
	if (!ft_strcmp(c, "|"))
		return (PIPE);
	if (!ft_strcmp(c, ">>"))
		return (APPEND_REDIR);
	if (!ft_strcmp(c, "<<"))
		return (HEREDOC);
	else
		return (CMD);
}
