/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:42:47 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 22:24:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_main(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal_num = 1;
	}
}

void	sigterm_main(int sig)
{
	if (sig == SIGTERM)
	{
		ft_putstr_fd("exit", 2);
		exit (143);
	}
}

void	sigquit_main(int sig)
{
	(void)sig;
}