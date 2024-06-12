/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/12 22:15:33 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_builtin(struct *something)
{
	char			*cur_dir_name;

	if (something->argv[1] == '~' || something->argv == 0)
	{	
		cur_dir_name = getenv("HOME");
		if (chdir(cur_dir_name) == -1)
			strerror(errno);
		return (-1);
	}
	else
	{
		if (chdir(something->argv[1]) == -1)
			strerror(errno);
		return (-1);
	}
	return (EXIT_SUCCESS);
}