/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:49:32 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:03:17 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list ap, const char format)
{
	unsigned int	len;

	len = 0;
	if (format == 'c')
		len = len + ft_pf_char(va_arg(ap, int));
	else if (format == 's')
		len = len + ft_pf_str(va_arg(ap, char *));
	else if (format == 'p')
		len = len + ft_pf_address(va_arg(ap, uintptr_t));
	else if (format == 'd')
		len = len + ft_pf_dec(va_arg(ap, int));
	else if (format == 'i')
		len = len + ft_pf_int(va_arg(ap, int));
	else if (format == 'u')
		len = len + ft_pf_unsigned_dec(va_arg(ap, unsigned int));
	else if (format == 'x')
		len = len + ft_pf_low_hex(va_arg(ap, unsigned int));
	else if (format == 'X')
		len = len + ft_pf_upp_hex(va_arg(ap, unsigned int));
	else if (format == '%')
		len = len + ft_pf_per();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	len;	

	va_start (ap, str);
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			len = len + check_format(ap, *str);
		}
		else
		{
			write(2, str, 1);
			len++;
		}
		str++;
	}
	va_end(ap);
	return (len);
}
