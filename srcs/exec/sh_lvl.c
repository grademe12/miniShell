/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lvl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:54:12 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/02 14:27:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	increase_shlvl(t_data *data)
{
	int		sh_lvl;
	int		i_lvl;
	char	*i_lvl_char;
	char	*ret;

	sh_lvl = check_dup(data, "SHLVL=", 5);
	if (sh_lvl == -1)
		return (-1);
	i_lvl = ft_atoi(data->envp[sh_lvl] + 6);
	i_lvl++;
	free(data->envp[sh_lvl]);
	i_lvl_char = ft_itoa(i_lvl);
	ret = ft_strjoin("SHLVL=", i_lvl_char);
	free(i_lvl_char);
	data->envp[sh_lvl] = ret;
	return (0);
}

int	decrease_shlvl(t_data *data)
{
	int		sh_lvl;
	int		i_lvl;
	char	*i_lvl_char;
	char	*ret;

	sh_lvl = check_dup(data, "SHLVL=", 5);
	if (sh_lvl == -1)
		return (-1);
	i_lvl = ft_atoi(data->envp[sh_lvl] + 6);
	i_lvl--;
	free(data->envp[sh_lvl]);
	i_lvl_char = ft_itoa(i_lvl);
	ret = ft_strjoin("SHLVL=", ft_itoa(i_lvl));
	free(i_lvl_char);
	data->envp[sh_lvl] = ret;
	return (0);
}
