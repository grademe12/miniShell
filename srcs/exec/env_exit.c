/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:30:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/22 23:48:30 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_builtin(t_data *data)
{
	int	i;

	i = 0;
	if (data->envp == 0)
		return (0);
	while (data->envp[i] != 0)
	{
		ft_putstr_fd(data->envp[i], 1);
		i++;
	}
}

int	exit_builtin(t_data *data)
{
	// must free all?
	exit(1);
}
