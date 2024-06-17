/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:47:37 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/17 20:10:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

// int	exec(void);
// int	check_builtin();
// int	exe_builtin(int val);
// int	echo_builtin(struct *something);

# define return_fail -10
# define CMD_NF -15
# define FILE 200
# define DIR 201

typedef struct s_data
{
	char	**envp;
	char	**argv;
	int		num_pipe;
}				t_data;

int		error_fun_ret(char *err_str, int errno);

#endif