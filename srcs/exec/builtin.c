/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:31:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/21 21:03:56 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_red_exe(t_data *data)
{
	t_token	*cur;
	int		errnum;

	cur = data->zero_token;
	errnum = 0;
	while (cur != 0)
	{
		errnum = check_red(data, cur);
		if (errnum != 0)
		{
			ft_errnum(errnum);
			return (errnum);
		}
		cur = cur->next;
	}
	remake_argv(data);
	exec_builtin(data);
}

