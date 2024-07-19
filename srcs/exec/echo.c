/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:42 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/19 15:11:32 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo_builtin(t_data *data)
{
	int	i;

	i = 1;
	while (data->argv[i] != 0)
	{
		ft_printf(data->argv[i]);
		ft_printf("\n");
		i++;
	}
	if (data->argv[1] == 0)
		ft_printf("\n");
	return (0);
}
