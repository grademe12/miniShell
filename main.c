/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:10 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/21 16:07:53 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	signal_num;

t_data	*data_init(char **envp)
{
	int		cnt;
	t_data	*ret;
	
	ret = (t_data *)malloc(sizeof(t_data));
	if (ret == 0)
		exit(1);
	cnt = 0;
	while (envp[cnt])
		cnt++;
	ret->envp = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (ret->envp == 0)
		exit (1);
	envp_alloc(ret, envp);
	ret->init_homepath = get_home_path(ret);
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	char	*read_line_str;
	t_data	*data;

	signal_num = 0;
	(void)argc;
    (void)argv;
	data = data_init(envp);
	// signal(SIGINT, sigint_handler);
	// signal(SIGQUIT, sigquit_handler);
	// signal(SIGTERM, sigeof_handler);
	increase_shlvl(data);
	while (1)
	{
		read_line_str = readline("minishell-test$ ");
		if (read_line_str == 0)
			return (0);
		if (*read_line_str != '\n')
			add_history(read_line_str);
		parsing(&data, read_line_str);
		exec(data);
	}
	decrease_shlvl(data);
	return (0);
}

//getenv 함수 구현하면 좋을듯