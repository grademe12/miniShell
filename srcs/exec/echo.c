/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:42 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/22 21:38:52 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo_builtin(t_data *data)
{
	int	i;

	i = 1;
	while (data->argv[i] != 0)
	{
		if (i != 1)
			printf(" %s", data->argv[i]);
		else
			printf ("%s", data->argv[i]);
		i++;
	}
	if (data->argv[i] == 0)
		printf("\n");
	return (0);
}
