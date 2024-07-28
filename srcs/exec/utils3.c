/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:17:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/28 08:34:50 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_home_path(t_data *data)
{
	int		home_index;
	char	*home_path;

	home_index = find_unset(data, "HOME=");
	if (home_index == -1)
		return (0);
	home_path = ft_strdup(data->envp[home_index] + 5);
	return (home_path);
}

void	fd_init(t_data *data)
{
	t_data *cur;

	cur = data;
	while (cur != 0)
	{
		data->last_fd = 0;
		cur = cur->next;
	}
}