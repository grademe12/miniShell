/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:30:18 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/01 17:41:40 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*sp1;
	char	*sp2;
	char	*ret_dup;

	if (!s1 || !s2)
		return (0);
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * \
	sizeof(char));
	if (!ret)
		return (0);
	ret_dup = ret;
	sp1 = s1;
	sp2 = s2;
	while (*sp1)
		*ret++ = *sp1++;
	while (*sp2)
		*ret++ = *sp2++;
	*ret = '\0';
	return (ret_dup);
}
