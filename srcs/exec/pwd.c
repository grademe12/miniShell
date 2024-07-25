/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:16:40 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/26 00:53:44 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd_builtin(t_data *data)
{
	char	cur_dir[4096];

	if (getcwd(cur_dir, 4096) == 0)
	{
		strerror(errno);
		return (-1);
	}
	else
		ft_putendl_fd(cur_dir, 1);
	(void)data;
	return (0);
}
