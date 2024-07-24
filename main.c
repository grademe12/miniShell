/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:10 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/25 07:10:43 by sanghhan         ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	data = data_init(envp);
	signal_main();
	increase_shlvl(data);
	while (1)
	{
		sig_print_off();
		read_line_str = readline("bfsh$ ");
		if (read_line_str == 0)
		{
			printf ("exit\n");
			exit(0);
		}
		if (*read_line_str != '\n' && ft_strlen(read_line_str) != 0)
			add_history(read_line_str);
		if (parsing(&data, read_line_str))
			exec(data);
	}
	decrease_shlvl(data);
	return (0);
}
