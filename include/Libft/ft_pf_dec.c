/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:50:12 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:04:06 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_dec(int num)
{
	char	*dec;
	int		len;

	len = 0;
	dec = ft_itoa(num);
	ft_putstr_fd(dec, 2);
	len = ft_strlen(dec);
	free(dec);
	return (len);
}
