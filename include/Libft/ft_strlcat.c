/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:47:37 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/25 14:12:54 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;
	size_t	i;
	size_t	j;

	if (dst == 0 && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dl > dstsize)
		return (dstsize + sl);
	while (src[j] != '\0' && dl + j + 1 < dstsize)
	{
		dst[i + dl] = src[j];
		i++;
		j++;
	}
	dst[j + dl] = '\0';
	return (sl + dl);
}
