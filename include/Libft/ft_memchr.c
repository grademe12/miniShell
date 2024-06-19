/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:30:14 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/11 19:12:08 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*cs;
	size_t			i;

	cc = (unsigned char)c;
	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(cs + i) == cc)
			return ((void *)cs + i);
		else
			i++;
	}
	return (NULL);
}
