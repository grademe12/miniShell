/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:01:08 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/19 13:49:46 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;
	unsigned int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[j] && i < n)
	{
		if (s1[i] != s2[j])
			break ;
		else if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (i == n)
			return (0);
	}
	return (s1[i] - s2[j]);
}
