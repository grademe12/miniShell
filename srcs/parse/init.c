/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:50:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/06/15 18:37:46 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_node(t_node *node)
{
	node->cmd = NULL;
	node->type = CMD;
	node->argv = NULL;
	node->next = NULL;
}
