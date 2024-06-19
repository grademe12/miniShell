/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:46:18 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/15 18:07:50 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_else(unsigned char *cd, const unsigned char *cs,
			size_t len, void *dst)
{
	while (len > 0)
	{
		len--;
		*cd = *cs;
		cd++;
		cs++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cd;
	const unsigned char	*cs;

	cd = (unsigned char *)dst;
	cs = (const unsigned char *)src;
	if (cd == NULL && cs == NULL)
		return (0);
	if (src < dst && src + len >= dst)
	{
		while (len > 0)
		{
			len--;
			*(cd + len) = *(cs + len);
		}
		return (dst);
	}
	else
		return (ft_else(cd, cs, len, dst));
}
