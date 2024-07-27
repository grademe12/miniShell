/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:01:08 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/26 20:10:23 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	ind;
	unsigned char	c1;
	unsigned char	c2;

	if (s1 == 0 || s2 == 0)
		return (0);
	ind = 0;
	c1 = 0;
	c2 = 0;
	while ((*s1 || *s2) && ind < n)
	{
		c1 = *s1;
		c2 = *s2;
		if (c1 != c2)
			return (c1 - c2);
		else
		{
			s1++ ;
			s2++ ;
			ind++ ;
		}
	}
	return (0);
}
