/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:05:32 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/21 15:56:56 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	errnum(int errnum_input)
{
	static int	errnum;

	errnum = errnum_input;
	return (errnum);
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

int	strerror_errno(int errno)
{
	strerror(errno);
	return (errno);
}

int	child_err_exit(char *str)
{
	strerror(errno);
	exit(1);
}
