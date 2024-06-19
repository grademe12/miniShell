/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:59:35 by woosupar          #+#    #+#             */
/*   Updated: 2024/05/10 11:59:38 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_pipe(char const *s1, char const *s2)
{
	char	*jp;
	char	*ret;	

	jp = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (jp == NULL)
		return (NULL);
	ret = jp;
	while (*s1 != '\0')
	{
		*jp = *s1;
		s1++;
		jp++;
	}
	*jp = '/';
	jp++;
	while (*s2 != '\0')
	{
		*jp = *s2;
		s2++;
		jp++;
	}
	*jp = '\0';
	return (ret);
}
