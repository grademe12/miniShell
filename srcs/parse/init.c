/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:50:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 05:37:12 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*new_token_node(char *token, t_type type)
{
	t_token	*node;

	node = ck_malloc(ft_calloc(1, sizeof(t_token)));
	node->token = token;
	node->type = type;
	return (node);
}

t_data	*new_data_node(char **ep, char **av, t_token *zt, char *homepath)
{
	t_data	*data;

	data = ck_malloc(ft_calloc(1, sizeof(t_data)));
	data->envp = ep;
	data->argv = av;
	data->init_homepath = homepath;
	data->zero_token = zt;
	return (data);
}
