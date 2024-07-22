/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:08:36 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/22 16:44:37 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	if (str == 0)
		return ;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
