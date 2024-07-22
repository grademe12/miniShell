/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:50:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/22 17:06:29 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*new_token_node(char *token, t_type type)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!node)
		exit_error();
	node->token = ft_strdup(token);
	node->type = type;
	node->next = NULL;
	return (node);
}

t_data	*new_data_node(char **ep, char **av, t_token *zt, int np)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit_error();
	data->envp = ep;
	data->argv = av;
	data->init_homepath = NULL;
	data->zero_token = zt;
	data->next = NULL;
	data->num_pipe = np;
	data->pids = NULL;
	return (data);
}
