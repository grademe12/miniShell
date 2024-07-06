/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:27 by woosupar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/06 19:47:44 by woosupar         ###   ########.fr       */
=======
/*   Updated: 2024/06/16 00:18:28 by sanghhan         ###   ########.fr       */
>>>>>>> 58208751a5ea28989e9aa7e9ef348a5e81b6d73f
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

<<<<<<< HEAD
int	data_init(char **envp, t_data *data, int argc, char **argv)
=======
int	main(int ac, char **av)
>>>>>>> 58208751a5ea28989e9aa7e9ef348a5e81b6d73f
{
	argc = 0;
	argv = 0;
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
	
	data = 0;
	if (data_init(envp, data, argc, argv) == return_fail)
		return (0);
	ft_errnum(0);
	increase_shlvl(data);
	make_oldpwd(data);
	while (1)
	{
<<<<<<< HEAD
		read_line_str = readline("minishell-test$ ");
=======
		read_line_str = readline(NULL);
>>>>>>> 58208751a5ea28989e9aa7e9ef348a5e81b6d73f
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
