/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:30:18 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/13 14:34:39 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*jp;
	char	*ret;

	if (s1 == 0 || s2 == 0)
		return (0);
	jp = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (jp == NULL)
		return (NULL);
	ret = jp;
	while (*s1 != '\0')
	{
		*jp = *s1;
		s1++;
		jp++;
	}
	while (*s2 != '\0')
	{
		*jp = *s2;
		s2++;
		jp++;
	}
	*jp = '\0';
	return (ret);
}
