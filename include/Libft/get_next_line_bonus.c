/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:47:18 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:26:59 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_read(int fd, t_gnl *gnl)
{
	ssize_t		read_value;

	read_value = read(fd, gnl->buf, BUFFER_SIZE);
	if (read_value > 0)
	{
		(gnl->buf)[read_value] = '\0';
		return (read_value);
	}
	else if (read_value == 0)
	{
		free(gnl->buf);
		gnl->buf = 0;
		return (-2);
	}
	else
	{
		clear_gnl(gnl, 0);
		return (-3);
	}
}

void	make_temp_no_malloc(t_gnl *gnl)
{
	ssize_t	i1;
	ssize_t	i2;

	if (gnl->len + BUFFER_SIZE > gnl->buffer)
	{
		gnl->buffer = (gnl->len + BUFFER_SIZE) * 5;
		gnl->temp = make_temp(gnl);
		return ;
	}
	i1 = gnl->len;
	i2 = -1;
	while (gnl->temp != 0 && (gnl->buf)[++i2] != '\0')
		gnl->temp[i1 + i2] = (gnl->buf)[i2];
	gnl->temp[i1 + i2] = '\0';
	gnl->len = i1 + i2;
}

char	*get_one_line(int fd, t_gnl *gnl, ssize_t idx)
{
	char	*one_line;
	ssize_t	val;

	idx = -1;
	while (idx == -1)
	{
		val = ft_read(fd, gnl);
		if (val == -3)
			return (0);
		if (val == -2)
		{
			one_line = make_one_line(gnl, gnl->len - 1, -2);
			clear_gnl(gnl, 0);
			return (one_line);
		}
		make_temp_no_malloc(gnl);
		idx = check_nl_temp(gnl);
		if (idx >= 0)
			return (make_one_line(gnl, idx, 0));
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl_array[1000];
	ssize_t			idx;

	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	if (gnl_array[fd].buf == 0)
	{
		gnl_array[fd].buf = (char *) malloc(BUFFER_SIZE + 1);
		if (gnl_array[fd].buf == 0)
		{
			clear_gnl(&gnl_array[fd], 0);
			return (0);
		}
	}
	idx = 0;
	while (gnl_array[fd].temp != 0 && gnl_array[fd].temp[idx] != '\0')
	{
		if (gnl_array[fd].temp[idx] == '\n')
			break ;
		idx++;
	}
	if (idx != gnl_array[fd].len)
		return (make_one_line(&gnl_array[fd], idx, 0));
	idx = -1;
	return (get_one_line(fd, &gnl_array[fd], idx));
}
