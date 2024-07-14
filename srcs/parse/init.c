/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:50:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/14 18:22:24 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*new_token_node(char *token, t_type type)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!node)
		exit_error();
	node->token = token;
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
	data->zero_token = zt;
	data->next = NULL;
	data->num_pipe = np;
	data->pids = NULL;
	return (data);
}
