/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:17:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/22 22:26:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_err_check_num(int check_num, char *str)
{
	if (check_num == 1)
		ft_printf("minish: cd: %s: No such file or directory\n", str);
	if (check_num == 2)
		ft_printf("minish: cd: %s: Not a directory\n", str);
	if (check_num == 3)
		ft_printf("minish: cd: %s: Permission denied\n", str);
	return (0);
}