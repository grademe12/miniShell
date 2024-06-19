/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:04:43 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/10 20:20:53 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*cs1 == *cs2)
		{
			cs1++;
			cs2++;
			n--;
		}
		else
			return (*cs1 - *cs2);
	}
	return (0);
}
