/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:10 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/02 16:43:02 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	g_signal_num;

t_data	*data_init(char **envp)
{
	int		cnt;
	int		old_pwd;
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
	old_pwd = check_dup(ret, "OLDPWD=", 6);
	if (old_pwd == -1)
		make_oldpwd(ret, "OLDPWD=");
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
		bfsh_rl(data);
		signal_main();
		read_line_str = readline("bfsh$ ");
		if (read_line_str == 0)
			print_exit();
		if (*read_line_str != '\n' && ft_strlen(read_line_str) != 0)
			add_history(read_line_str);
		if (parsing(&data, read_line_str))
			exec(data);
		free(read_line_str);
	}
	decrease_shlvl(data);
	return (g_signal_num);
}

void	print_exit(void)
{
	printf ("\033[1A\033[6Cexit\n");
	g_signal_num = 0;
	exit(0);
}

void	bfsh_rl(t_data *data)
{
	if (g_signal_num == 130 && data->num_pipe == 0)
		ft_putstr_fd("\033[6D\033[1A\033[E", 2);
	else if (g_signal_num == 130 && data->num_pipe != 0)
		ft_putstr_fd("\n\033[6D\033[E\033[1B", 2);
	else if (g_signal_num == 131)
		ft_putstr_fd("Quit: 3\n", 2);
}
