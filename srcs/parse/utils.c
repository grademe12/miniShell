/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:57:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/16 19:08:09 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	exit_error(void)
{
	perror("Error!\n");
	exit(1);
}

int	check_quote(char c, int *sq, int *dq)
{
	if ((*sq || *dq) || (c == '\'' || c == '\"'))
	{
		if (c == '\'' && !*dq)
			*sq = !(*sq);
		if (c == '\"' && !*sq)
			*dq = !(*dq);
		return (1);
	}
	return (0);
}
