/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/15 14:01:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_builtin(t_data *data)
{
	char			*cur_dir_name;

	if (data->argv[1] == '~' || data->argv == 0)
	{	
		cur_dir_name = getenv("HOME");
		if (chdir(cur_dir_name) == -1)
			strerror(errno);
		return (-1);
	}
	else
	{
		if (chdir(data->argv[1]) == -1)
			strerror(errno);
		return (-1);
	}
	return (EXIT_SUCCESS);
}