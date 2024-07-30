/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:16:40 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 13:10:14 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd_builtin(t_data *data)
{
	printf ("%p\n", data->pwd);
	int i = 0;
	while (data->envp[i] != 0)
	{
		printf ("%s\n", data->envp[i]);
		i++;
	}
	ft_putendl_fd(data->pwd, 1);
	(void)data;
	return (0);
}
