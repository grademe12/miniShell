/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:37:54 by woosupar          #+#    #+#             */
/*   Updated: 2023/10/13 14:24:40 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	c = (char )c;
	while (*ret != '\0')
	{
		if (c == *ret)
			return (ret);
		else
			ret++;
	}
	if (c == 0)
		return (ret++);
	return (0);
}
