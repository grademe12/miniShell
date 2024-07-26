/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:30:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/26 23:51:55 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_builtin(t_data *data)
{
	int	i;

	i = 0;
	if (data->envp == 0)
	{
		ft_putstr_fd("bfsh: env: Can't find environment variables.\n", 2);
		g_signal_num = 1;
	}
	if (data->argv[1] == 0)
	{
		while (data->envp[i] != 0)
		{
			ft_putstr_fd(data->envp[i], 1);
			ft_putchar_fd('\n', 1);
			i++;
		}
	}
	else
		return (RET_FAIL);
	return (0);
}
