/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:31:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 14:00:06 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_red_exe(t_data *data, int val)
{
	t_token	*cur;
	int		ret_code;

	cur = data->zero_token;
	while (cur != 0)
	{
		g_signal_num = check_red(data, cur);
		if (g_signal_num != 0)
		{
			g_signal_num = 1;
			return (g_signal_num);
		}
		cur = cur->next;
	}
	remake_argv(data);
	ret_code = exe_builtin(data, val);
	return (ret_code);
}
