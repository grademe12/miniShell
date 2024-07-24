/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:58 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 18:56:09 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf ("\n");
		g_signal_num = 128 + SIGINT;
	}
}

void	sigterm_handler(int sig)
{
	if (sig == SIGTERM)
		g_signal_num = 128 + SIGTERM;
}

void	sigquit_handler(int sig)
{
	if (sig == SIGQUIT)
	{	
		g_signal_num = 128 + SIGQUIT;
	}
}

void	sigquit_handler_child(int sig)
{
	if (sig == SIGQUIT)
		exit(131);
}