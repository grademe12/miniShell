/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:36:57 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/15 18:08:36 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_minus(char *itoa, int len, int n)
{
	if (itoa == 0)
		return (0);
	itoa[len + 1] = '\0';
	if (n == 0)
	{
		itoa[0] = '0';
		return (itoa);
	}
	while (len > 0)
	{
		itoa[len] = -1 * (n % 10) + '0';
		n = n / 10;
		len--;
	}
	itoa[0] = '-';
	return (itoa);
}

static char	*if_plus(char *itoa, int len, int n)
{
	if (itoa == 0)
		return (0);
	itoa[len] = '\0';
	while (len > 0)
	{
		len--;
		itoa[len] = n % 10 + '0';
		n = n / 10;
	}
	return (itoa);
}

char	*ft_itoa(int n)
{
	int		len;
	int		on;
	char	*itoa;

	len = 0;
	on = n;
	while (n != 0)
	{	
		n = n / 10;
		len++;
	}
	n = on;
	if (n <= 0)
	{
		itoa = (char *) malloc((len + 2) * sizeof(char));
		return (if_minus(itoa, len, n));
	}
	else
	{
		itoa = (char *) malloc((len + 1) * sizeof(char));
		return (if_plus(itoa, len, n));
	}
	return (itoa);
}
