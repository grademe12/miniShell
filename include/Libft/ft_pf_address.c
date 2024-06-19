/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:49:58 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:03:55 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_null(uintptr_t add)
{
	add = 0;
	return (write(2, "0x0", 3));
}

int	add_len(unsigned long long add)
{
	int	len;

	len = 0;
	while (add != 0)
	{
		add = add / 16;
		len++;
	}
	return (len);
}

int	ft_pf_address(uintptr_t add)
{
	int		len;
	int		i;
	char	arr[17];

	if (add == 0)
		return (add_null(add));
	len = add_len(add);
	i = 0;
	while (add != 0)
	{
		arr[i] = add % 16;
		if (9 < arr[i] && arr[i] < 16)
			arr[i] = arr[i] + 87;
		else
			arr[i] = arr[i] + '0';
		add = add / 16;
		i++;
	}
	arr[i] = '\0';
	write (2, "0x", 2);
	while (--i >= 0)
		write (2, &arr[i], 1);
	return (len + 2);
}
