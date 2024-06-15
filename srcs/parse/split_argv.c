/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:49:38 by sanghhan          #+#    #+#             */
/*   Updated: 2024/06/13 23:20:29 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_sep(char c, int *single_quote, int *double_quote)
{
    if (*single_quote || *double_quote)
        return (0);
    if (c == ' ')
        return (1);
    return (0);
}