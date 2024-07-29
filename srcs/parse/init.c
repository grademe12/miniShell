/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:50:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 06:27:26 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*new_token_node(char *token, t_type type)
{
	t_token	*node;

	node = ck_malloc(ft_calloc(1, sizeof(t_token)));
	node->token = token;
	node->type = type;
	node->next = NULL;
	return (node);
}

t_data	*new_data_node(char **av, t_token *zt, t_data *prev)
{
	t_data	*data;

	data = ck_malloc(ft_calloc(1, sizeof(t_data)));
	data->envp = prev->envp;
	data->argv = av;
	data->init_homepath = prev->init_homepath;
	data->zero_token = zt;
	data->next = NULL;
	data->num_pipe = 0;
	data->last_fd = 0;
	data->pwd = prev->pwd;
	return (data);
}
