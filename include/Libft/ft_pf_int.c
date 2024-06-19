/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:50:15 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:04:18 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_int(int num)
{
	char	*integer;
	int		len;

	len = 0;
	integer = ft_itoa(num);
	ft_putstr_fd(integer, 2);
	len = ft_strlen(integer);
	free(integer);
	return (len);
}
