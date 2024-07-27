/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:05:32 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/27 10:21:39 by woosupar         ###   ########.fr       */
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
	g_signal_num = 1;
	exit (1);
}

void	err_print(char *cmd, int err)
{
	ft_putstr_fd("bfsh: ", 2);
	if (cmd != 0)
		ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(err), 2);
	ft_putchar_fd('\n', 2);
}

int	child_err_exit(int err, char *str)
{
	ft_putstr_fd("bfsh: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(err), 2);
	ft_putchar_fd('\n', 2);
	if (err == 13)
		exit (126);
	exit (1);
}
