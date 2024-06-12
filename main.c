/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/12 15:17:48 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main()
{
	char	*read_line_str;

	while (TRUE)
	{
		read_line_str = readline("minishell-test$ ");
		if (read_line_str == 0)
		{
			return (0);
		}
		else
		{
			//parse();
			exec();
		}
	}
	return (0);
}