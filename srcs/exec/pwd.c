/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:16:40 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/12 22:29:44 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd_builtin(struct *something)
{
	char	*cur_dir;

	cur_dir = 0;
	if (getcwd(cur_dir, 0) == 0)
	{	
		strerror(errno);
		return (-1);
	}
	else
		ft_putendl_fd(cur_dir, 1);
	return (0);
}