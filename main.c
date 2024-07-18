/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:10 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/18 18:32:13 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

volatile sig_atomic_t	signal_num;

int	data_init(char **envp, t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == 0)
		return (RET_FAIL);
	data->envp = envp;
	data->init_homepath = get_home_path(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*read_line_str;
	t_data	*data;

	(void)argc;
    (void)argv;
	data = 0;
	if (data_init(envp, data) == RET_FAIL)
		return (0);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGTERM, sigeof_handler);
	increase_shlvl(data);
	make_oldpwd(data);
	while (1)
	{
		signal_num = 0;
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
