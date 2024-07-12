/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:57:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/12 23:29:41 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	exit_error(void)
{
	perror("Error!\n");
	exit(1);
}

int	check_quote(char c, int *sq, int *dq, int is_escape)
{
	if ((*sq || *dq) || ((c == '\'' || c == '\"') && !is_escape))
	{
		if (c == '\'' && !*dq && !is_escape)
			*sq = !(*sq);
		if (c == '\"' && !*sq && !is_escape)
			*dq = !(*dq);
		return (1);
	}
	return (0);
}

// t_type	get_type(char *c)
// {
// 	if (!ft_strcmp(c, ">"))
// 		return (OUTPUT_REDIR);
// 	if (!ft_strcmp(c, "<"))
// 		return (INPUT_REDIR);
// 	if (!ft_strcmp(c, "|"))
// 		return (PIPE);
// 	if (!ft_strcmp(c, ">>"))
// 		return (APPEND_REDIR);
// 	if (!ft_strcmp(c, "<<"))
// 		return (HEREDOC);
// 	else
// 		return (CMD);
// }
