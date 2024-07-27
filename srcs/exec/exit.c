/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:18:51 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/26 23:58:51 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exit_builtin(t_data *data)
{
	int	code;

	if (data->argv[1] == 0)
		exit(0);
	if (ft_str_isdigit(data->argv[1]) != 0 || ft_strlen(data->argv[1]) > 8)
	{
		ft_putstr_fd("bfsh: exit: ", 2);
		ft_putstr_fd(data->argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit (2);
	}
	if ((ft_str_isdigit(data->argv[1]) == 0) && (data->argv[2] != 0))
	{
		ft_putstr_fd("bfsh: exit: too many arguments\n", 2);
		g_signal_num = 127;
		return (0);
	}
	code = make_code(ft_atoi(data->argv[1]));
	exit(code);
}

int	make_code(int ori)
{
	int	rem;
	int	m;

	m = 0;
	if (ori < 0)
	{
		m = 1;
		ori = ori * -1;
	}
	rem = ori % 256;
	if (m == 0)
		return (rem);
	else
		return (256 - rem);
}
