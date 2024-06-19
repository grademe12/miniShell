/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:43:36 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/27 21:45:51 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_sen(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (1)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cnt);
}

static void	str_split(char *split, char const *s, size_t i, size_t may)
{
	size_t	k;

	k = 0;
	while (k + may < i)
	{
		split[k] = s[may + k];
		k++;
	}
	split[k] = '\0';
}

static void	ft_free(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**do_split(char const *s, char c, char **split, size_t i)
{
	size_t	may;
	size_t	j;

	j = 0;
	while (1)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		may = i;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		split[j] = (char *) malloc ((i - may + 1) * sizeof(char));
		if (split[j] == 0)
		{
			ft_free(split, j);
			return (0);
		}
		str_split(split[j], s, i, may);
		j++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	split = (char **) malloc((num_sen(s, c) + 1) * sizeof(char *));
	if (split == 0)
		return (0);
	split[num_sen(s, c)] = 0;
	return (do_split(s, c, split, i));
}
