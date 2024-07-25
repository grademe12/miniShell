/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:10 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/25 15:56:48 by woosupar         ###   ########.fr       */
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
	increase_shlvl(data);
	while (1)
	{
		signal_main();
		sig_print_off();
		read_line_str = readline("bfsh$ ");
		if (read_line_str == 0)
		{
			printf ("\033[1A\033[6Cexit\n");
			g_signal_num = 143;
			exit(143);
		}
		if (*read_line_str != '\n' && ft_strlen(read_line_str) != 0)
			add_history(read_line_str);
		if (parsing(&data, read_line_str))
			exec(data);
	}
	decrease_shlvl(data);
	return (g_signal_num);
}
