/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:40:35 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/13 14:25:07 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char const *s, int c)
{
	char const	*cpy;

	cpy = s;
	c = (char )c;
	while (*cpy != '\0')
		cpy++;
	s--;
	while (s != cpy)
	{
		if (*cpy == c)
			return ((char *)cpy);
		else
			cpy--;
	}
	return (0);
}
