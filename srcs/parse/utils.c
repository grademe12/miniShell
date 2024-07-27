/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:57:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/26 21:35:39 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	exit_error(void)
{
	perror("Error!\n");
	exit(1);
}

int	check_quote(char c, int *sq, int *dq)
{
	if ((*sq || *dq) || (c == '\'' || c == '\"'))
	{
		if (c == '\'' && !*dq)
			*sq = !(*sq);
		if (c == '\"' && !*sq)
			*dq = !(*dq);
		return (1);
	}
	return (0);
}

void	free_parse_error(t_data **begin)
{
	t_data	*nowdata;
	t_data	*temp;
	int		i;

	nowdata = *begin;
	while (nowdata)
	{
		if (nowdata->zero_token)
		{
			free_token(&nowdata->zero_token);
			nowdata->zero_token = NULL;
		}
		if (nowdata->argv)
		{
			i = -1;
			while (nowdata->argv[++i])
				free(nowdata->argv[i]);
		}
		free(nowdata->argv);
		nowdata->argv = NULL;
		temp = nowdata;
		nowdata = nowdata->next;
		free(temp);
	}
	*begin = NULL;
}

void	parse_error(char *token)
{
	printf ("bfsh: syntax error near unexpected token `%s'\n", token);
	g_signal_num = 258;
}
