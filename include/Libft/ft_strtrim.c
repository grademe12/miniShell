/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:23:55 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/27 21:45:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *s1, char const *set, size_t i)
{
	int		j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
			return (1);
		j++;
	}
	return (0);
}

static char	*do_trim(size_t trim_len, size_t s1_len, size_t i, char const *s1)
{
	char	*trim;

	trim = (char *) malloc((trim_len + 1) * sizeof(char));
	if (trim == 0)
		return (0);
	while (i < s1_len)
	{
		*trim = s1[i];
		trim++;
		i++;
	}
	*trim = '\0';
	return (trim - trim_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	trim_len;
	size_t	i;

	if (s1 == 0)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	trim_len = s1_len;
	while (ft_isset(s1, set, i) == 1 && s1[i] != '\0')
	{
		trim_len--;
		i++;
	}
	if (trim_len == 0)
		return (do_trim(trim_len, s1_len, i, s1));
	while (ft_isset(s1, set, s1_len - 1) == 1 && s1_len > 0)
	{
		trim_len--;
		s1_len--;
	}
	return (do_trim(trim_len, s1_len, i, s1));
}
