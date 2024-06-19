/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:23:02 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/12 18:48:42 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*cd;
	const char		*cs;
	size_t			num;

	if (dst == 0 && src == 0)
		return (0);
	cd = (char *)dst;
	cs = (const char *)src;
	num = 0;
	while (num < n)
	{
		*cd = *cs;
		cd++;
		cs++;
		num++;
	}
	return (dst);
}
