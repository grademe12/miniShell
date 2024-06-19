/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:49:48 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/12 18:58:03 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cb;
	unsigned char	cc;

	cb = (unsigned char *)b;
	cc = (unsigned char)c;
	while (len > 0)
	{
		*cb = cc;
		cb++;
		len--;
	}
	return (b);
}
