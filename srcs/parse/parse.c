/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:56:43 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/12 18:09:50 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_quote(char c, int *single_quote, int *double_quote, int is_escape)
{
	if (*single_quote || *double_quote || c == '\'' || c == '\"')
	{
		if (c == '\'' && !*double_quote && !is_escape)
			*single_quote = !(*single_quote);
		if (c == '\"' && !*single_quote && !is_escape)
			*double_quote = !(*double_quote);
		return (1);
	}
	return (0);
}
