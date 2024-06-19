/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:40:42 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/25 15:18:10 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isnum(int i, const char *str)
{
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	ft_isspace(int i, const char *str)
{
	while (str[i] != '\0')
	{
		if ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	ft_conv(int i, const char *str)
{
	int		num;

	num = 0;
	while (ft_isnum(i, str) == 1)
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(i, str) == 1)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	num = ft_conv(i, str);
	return (sign * num);
}
