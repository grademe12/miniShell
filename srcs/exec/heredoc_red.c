/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_red.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:48:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/27 21:01:05 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	heredoc_red_dup(int fd, int flag)
{
	int	stdin;

	stdin = dup(STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) == -1)
		inner_function_error("dup2 error\n");
	close(fd);
	if (flag == 1)
		if (dup2(stdin, STDIN_FILENO) == -1)
			inner_function_error("dup2 error\n");
	close(stdin);
	return (0);
}