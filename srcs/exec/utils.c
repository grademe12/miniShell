/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:05:32 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 01:25:23 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	error_fun_ret(char *err_str, int errno)
{
	printf ("%s: %s", err_str, strerror(errno));
	return (errno);
}

int	is_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (-1);
}

void	inner_function_error(char *str)
{
	ft_putstr_fd(2, str);
	exit (1);
}