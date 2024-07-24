/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:58 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 14:07:11 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int sig, t_data *data)
{
	int	i;

	i = 0;
	if (sig == SIGINT && data->pids)
	{
		while (data->pids[i])
		{	
			kill(data->pids[i], SIGKILL);
			i++;
		}
		ft_putstr_fd("^C", 2);
	}
	else if (sig == SIGINT && !(data->pids))
		return ;
}

void	sigeof_handler(int sig)
{
	if (sig == SIGTERM)
		g_signal_num = EOF;
}

void	sigquit_handler(int sig)
{
	sig = 0;
	(void)sig;
	return ;
}
