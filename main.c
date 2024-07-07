/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:10 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/07 18:02:34 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	data_init(char **envp, t_data *data, int argc, char **argv)
{
	argc = 0;
	argv = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (data == 0)
		return (RET_FAIL);
	data->envp = envp;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*read_line_str;
	t_data	*data;
	
	data = 0;
	if (data_init(envp, data, argc, argv) == RET_FAIL)
		return (0);
	ft_errnum(0);
	increase_shlvl(data);
	make_oldpwd(data);
	while (1)
	{
		read_line_str = readline("minishell-test$ ");
		if (read_line_str == 0)
			return (0);
		if (*read_line_str != '\n')
			add_history(read_line_str);
		parse(data);
		exec(data);
	}
	decrease_shlvl(data);
	return (0);
}
