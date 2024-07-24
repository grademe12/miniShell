/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:42:54 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/24 22:11:44 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, sigquit_child);
	signal(SIGTERM, SIG_DFL);
}

void	sigquit_child(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 2);
	}
}