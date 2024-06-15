/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/16 00:18:28 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int ac, char **av)
{
	char	*read_line_str;

	while (TRUE)
	{
		read_line_str = readline(NULL);
		if (read_line_str == 0)
		{
			return (0);
		}
		else
		{
			return (0);
		}
	}
	return (0);
}
