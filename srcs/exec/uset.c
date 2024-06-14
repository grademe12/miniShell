/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uset.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:30:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/14 22:42:33 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	unset_builtin(struct *something, t_data *data)
{
	char	*str;
	int		i;
	
	str = data->node->argv[1];
	i = 0;
	if (str == 0)
		return (0);
	while (data->envp[i] != 0)
	{
		if (ft_strncmp(str, data->envp[i], ft_strlen(str)) == 0)
			break ;
		i++;
	}
	if (data->envp[i] == 0)
		return (0);
	free(envp[i]);
	envp[i] = 0;
	return (0);
}

int	env_builtin(t_data *data)
{
	int	i;

	i = 0;
	if (data->envp == 0)
		return (0);
	while (data->envp[i] != 0)
	{
		ft_putendl_fd(data->envp[i], 1);
		i++;
	}
}

int	exit_builtin(t_data *data)
{
	// must free all?
	exit(1);
}