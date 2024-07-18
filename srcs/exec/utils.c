/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:05:32 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/18 22:03:43 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	ft_putstr_fd(str, 2);
	signal_num = errno;
	exit (1);
}

int	strerror_errno(int err)
{
	strerror(err);
	return (err);
}

int	child_err_exit(int err)
{
	strerror(err);
	exit(err);
}
