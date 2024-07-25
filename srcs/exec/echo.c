/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:42 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/25 19:12:23 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo_builtin(t_data *data)
{
	int	i;
	int	op;

	i = 1;
	op = 0;
	if (ft_strcmp(data->argv[i], "-n") == 0)
	{	
		op = 1;
		i = i + op;
	}
	while (data->argv[i] != 0)
	{
		if (i == 1 + op)
			printf ("%s", data->argv[i]);
		else
			printf (" %s", data->argv[i]);
		i++;
	}
	if (op != 1 && data->argv[i] == 0)
		printf("\n");
	return (0);
}
