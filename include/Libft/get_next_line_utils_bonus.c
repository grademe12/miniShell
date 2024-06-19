/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:53:31 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:29:56 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clear_gnl(t_gnl *gnl, ssize_t flag)
{
	free(gnl->temp);
	gnl->temp = 0;
	if (flag != 1)
	{
		free(gnl->buf);
		gnl->buf = 0;
		gnl->buffer = 0;
		gnl->len = 0;
		gnl->nl_index = 0;
	}
}

ssize_t	check_nl_temp(t_gnl *gnl)
{
	while (gnl->temp && gnl->temp[gnl->nl_index] != '\0')
	{
		if (gnl->temp[gnl->nl_index] == '\n')
			return (gnl->nl_index);
		gnl->nl_index++;
	}
	return (-1);
}

char	*make_temp(t_gnl *gnl)
{
	ssize_t	i1;
	ssize_t	i2;
	char	*str;

	i1 = 0;
	i2 = -1;
	str = (char *) malloc(gnl->buffer + 1);
	if (str == 0)
	{
		clear_gnl(gnl, 0);
		return (0);
	}
	while ((gnl->temp != 0 && (gnl->temp)[i1] != '\0'))
	{
		str[i1] = (gnl->temp)[i1];
		i1++;
	}
	while ((gnl->buf)[++i2] != '\0')
		str[i1 + i2] = (gnl->buf)[i2];
	str[i1 + i2] = '\0';
	gnl->len = i1 + i2;
	clear_gnl(gnl, 1);
	return (str);
}

char	*make_one_line(t_gnl *gnl, ssize_t nl_index, ssize_t flag)
{
	char	*str;
	ssize_t	str_idx;

	str_idx = 0;
	if (gnl->temp == 0 || gnl->temp[0] == '\0')
	{
		clear_gnl(gnl, 0);
		return (0);
	}
	str = (char *) malloc(nl_index + 2);
	if (str == 0)
	{
		clear_gnl(gnl, 0);
		return (0);
	}
	while (str_idx < nl_index + 1)
	{
		str[str_idx] = (gnl->temp)[str_idx];
		str_idx++;
	}
	str[str_idx] = '\0';
	if (flag != -2)
		ft_memmove_gnl(gnl, nl_index);
	return (str);
}

void	ft_memmove_gnl(t_gnl *gnl, ssize_t temp_idx)
{
	char	*dst;
	char	*src;
	ssize_t	a;
	ssize_t	len;

	a = 0;
	len = 0;
	dst = gnl->temp;
	src = gnl->temp + temp_idx + 1;
	while (temp_idx + a < gnl->len)
	{
		dst[a] = src[a];
		a++;
	}
	while (a < gnl->buffer)
	{
		*(dst + a) = '\0';
		a++;
	}
	while (gnl->temp[len] != '\0')
		len++;
	gnl->len = len;
	gnl->nl_index = 0;
}
