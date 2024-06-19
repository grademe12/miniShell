/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_unsigned_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:50:26 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:04:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_itoa(unsigned int num)
{
	int				len;
	long long		on;
	char			*itoa;

	len = 0;
	on = num;
	while (on != 0)
	{	
		on = on / 10;
		len++;
	}
	itoa = (char *) malloc((len + 1) * sizeof(char));
	if (itoa == 0)
		return (0);
	itoa[len] = '\0';
	while (--len > -1)
	{
		itoa[len] = num % 10 + '0';
		num = num / 10;
	}
	return (itoa);
}

int	ft_pf_unsigned_dec(unsigned int num)
{
	char	*dec;
	int		len;

	if (num > 4294967295)
		return (-1);
	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (num < 0)
		num = 4294967295 + num + 1;
	len = 0;
	dec = ft_unsigned_itoa(num);
	ft_putstr_fd(dec, 2);
	len = ft_strlen(dec);
	free(dec);
	return (len);
}