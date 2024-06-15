/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:12:20 by sanghhan          #+#    #+#             */
/*   Updated: 2024/06/16 01:01:39 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_strip(char	**str)
{
	size_t	start_ind;
	size_t	end_ind;
	char	*ret;

	start_ind = 0;
	end_ind = ft_strlen(*str);
	if (end_ind == 0)
		return (0);
	if (str[start_ind] == ' ')
		start_ind ++;
	if (str[end_ind] == ' ')
		end_ind-- ;
	ret = ft_substr(str, start_ind, end_ind - start_ind + 1);
	if (!ret)
		return (0);
	free(*str);
	*str = ret;
	return (1);
}
