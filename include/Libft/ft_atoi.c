/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:40:42 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/26 19:32:35 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++ ;
	if ((*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++ ;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		str++ ;
	}
	return (num * sign);
}
