/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:30:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 21:30:19 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_builtin(t_data *data)
{
	int	i;

	i = 0;
	if (data->envp == 0)
		return (-1);
	while (data->envp[i] != 0)
	{
		ft_putstr_fd(data->envp[i], 1);
		ft_printf("\n");
		i++;
	}
	return (0);
}

int	exit_builtin(t_data *data)
{
	(void)data;
	exit(1);
}
