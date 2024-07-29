/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:11:51 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 06:24:20 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	start = (size_t)start;
	if (ft_strlen(s) <= start || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ss = (char *) malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
