/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:10 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/25 05:28:26 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	g_signal_num;

t_data	*data_init(char **envp)
{
	int		cnt;
	t_data	*ret;

	ret = (t_data *)ft_calloc(1, sizeof(t_data));
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
	int 	parse;

	(void)argc;
	(void)argv;
	data = data_init(envp);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGTERM, sigterm_handler);
	increase_shlvl(data);
	while (1)
	{
		g_signal_num = 0;
		read_line_str = readline("bfsh$ ");
		if (read_line_str == 0)
			return (0);
		if (*read_line_str != '\n' && ft_strlen(read_line_str) != 0)
			add_history(read_line_str);
		parse = parsing(&data, read_line_str);
		free(read_line_str);
		if (!parse)
			continue ;
		exec(data);
		if (g_signal_num == 143)
			exit(1);
		if (g_signal_num == 131)
			printf ("Quit: 3\n");
	}
	decrease_shlvl(data);
	return (0);
}
