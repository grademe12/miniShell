/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:31:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 20:06:59 by woosupar         ###   ########.fr       */
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
		signal_num = check_red(data, cur);
		if (signal_num != 0)
		{
			signal_num = 1;
			return (signal_num);
		}
		cur = cur->next;
	}
	remake_argv(data);
	ret_code = exe_builtin(data, val);
	return (ret_code);
}
