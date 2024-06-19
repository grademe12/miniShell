/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_low_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:50:18 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:04:32 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int hex)
{
	int	len;

	len = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}

int	ft_pf_low_hex(unsigned int hex)
{
	int		len;
	int		i;
	char	arr[9];

	if (hex == 0)
	{
		write (2, "0", 1);
		return (1);
	}
	len = hex_len(hex);
	i = 0;
	while (hex != 0)
	{
		arr[i] = hex % 16;
		if (9 < arr[i] && arr[i] < 16)
			arr[i] = arr[i] + 87;
		else
			arr[i] = arr[i] + '0';
		hex = hex / 16;
		i++;
	}
	arr[i] = '\0';
	while (--i >= 0)
		write (2, &arr[i], 1);
	return (len);
}
