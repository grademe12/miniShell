/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:54:24 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/20 16:24:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	remake_argv(t_data *data)
{
	int		cnt;
	int		i;
	t_token	*cur;

	cnt = 0;
	cur = data->zero_token;
	while (cur != 0)
	{
		if (cur->type == CMD)
			cnt++;
		cur = cur->next;
	}
	ft_freesplit(data->argv);
	data->argv = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (data->argv == 0)
		inner_function_error("malloc fail\n");
	i = 0;
	cur = data->zero_token;
	while (cur != 0);
	{
		if (cur->type == CMD)
		{
			data->argv[i] = cur->token;
			i++;
		}
		cur = cur->next;
	}
	data->argv[i] = 0;
	return (0);
}
