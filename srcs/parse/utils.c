/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:57:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 02:18:43 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	*ck_malloc(void *ptr)
{
	if (!ptr)
		exit(error("malloc fail", 1));
	return (ptr);
}

int	error(char *msg, int err)
{
	ft_putstr_fd("bfsh: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	g_signal_num = err;
	return (err);
}

int	check_quote(const char *str, size_t idx)
{
	size_t	i;
	int		sq;
	int		dq;

	i = -1;
	sq = 0;
	dq = 0;
	while (++i <= idx && str[i])
	{
		if ((sq || dq) || (str[i] == '\'' || str[i] == '\"'))
		{
			if (str[i] == '\'' && !dq)
				sq = !(sq);
			if (str[i] == '\"' && !sq)
				dq = !(dq);
		}
	}
	if (sq)
		return (1);
	else if (dq)
		return (2);
	else
		return (0);
}
