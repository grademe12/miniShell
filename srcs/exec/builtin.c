/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:31:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/22 21:37:42 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_red_exe(t_data *data, int val)
{
	t_token	*cur;

	cur = data->zero_token;
	while (cur != 0)
	{
		signal_num = check_red(data, cur);
		if (signal_num != 0)
		{
			signal_num = 1;
			return (signal_num);
		}
		cur = cur->next;
	}
	remake_argv(data);
	exe_builtin(data, val);
	return (0);
}
