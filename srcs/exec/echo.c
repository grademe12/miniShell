/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:42 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/12 21:37:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo_builtin(struct *something)
{
	char	**str;
	int		i;

	i = 1;
	while (something->argv[i] != 0)
		ft_putstr_fd(something->argv[i], 1);
