/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:21:06 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 20:27:03 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*multi_heredoc(char *str)
{
	char	*ret;

	ret = ft_strjoin(str, "doc");
	if (ret == 0)
		inner_function_error("malloc fail\n");
	return (ret);
}