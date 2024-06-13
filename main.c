/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/13 21:34:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	data_init(char **envp, t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == 0)
		return (return_fail);
	data->envp = envp;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*read_line_str;
	t_data	*data;
	
	if (data_init(envp, data) == return_fail)
		return (0);
	while (1)
	{
		read_line_str = readline("minishell-test$ ");
		if (read_line_str == 0)
		{
			return (0);
		}
		else
		{
			//parse();
			//exec();
		}
	}
	return (0);
}