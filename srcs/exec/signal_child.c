/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:42:54 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/26 00:55:21 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	signal_child(void)
{
	sig_print_on();
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
}

void	sigquit_child(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit: 3\n", 2);
}

void	sigint_child(int sig)
{
	(void)sig;
	exit (128 + SIGINT);
}
