/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:31:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/06 22:29:23 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_red_exe(t_data *data, int val)
{
	t_token	*cur;
	int		errnum;

	cur = data->zero_token;
	while (cur != 0)
	{
		errnum = check_red(data, cur);
		if (errnum != 0)
			return (errnum);
		cur = cur->next;
	}
	remake_argv(data);
	exe_builtin(data, val);
	return (0);
}

