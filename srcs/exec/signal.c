/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:58 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/25 14:27:35 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	signal_main(void)
{
	// signal(SIGTERM, sigterm_main);
	signal(SIGINT, sigint_main);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	sig_print_on(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}
