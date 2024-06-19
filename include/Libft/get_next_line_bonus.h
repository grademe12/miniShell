/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:00:34 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/19 14:29:40 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# elif BUFFER_SIZE <= 0
#  error "error"
# endif

typedef struct s_gnl
{
	char	*temp;
	char	*buf;
	ssize_t	nl_index;
	ssize_t	len;
	ssize_t	buffer;
}				t_gnl;

char	*make_temp(t_gnl *gnl);
char	*make_one_line(t_gnl *gnl, ssize_t nl_index, ssize_t flag);
void	ft_memmove_gnl(t_gnl *gnl, ssize_t temp_idx);
char	*get_next_line(int fd);
char	*get_one_line(int fd, t_gnl *gnl, ssize_t idx);
ssize_t	ft_read(int fd, t_gnl *gnl);
ssize_t	check_nl_temp(t_gnl *gnl);
void	clear_gnl(t_gnl *gnl, ssize_t flag);
void	make_temp_no_malloc(t_gnl *gnl);

#endif
