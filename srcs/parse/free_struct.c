/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:16:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/21 16:16:02 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	free_strarr(char **word_arr, size_t i)
{
	size_t	ind;

	ind = 0;
	while (ind <= i)
	{
		free(word_arr[ind]);
		ind++;
	}
	free(word_arr);
	return (1);
}

int	free_token(t_token **begin)
{
	t_token	*nowtoken;
	t_token *temp;

	nowtoken = *begin;
	while (nowtoken)
	{
		free(nowtoken->token);
		nowtoken->token = NULL;
		temp = nowtoken;
		nowtoken = nowtoken->next;
		free(temp);
	}
	*begin = NULL;
	return(1);
}

int	free_data(t_data **begin)
{
	t_data	*nowdata;
	t_data	*temp;
	int		i;

	nowdata = *begin;
	while (nowdata)
	{
		if (nowdata->zero_token)
			free_token(&nowdata->zero_token);
		else if (nowdata->argv)
		{
			i = -1;
			while (nowdata->argv[++i])
				free(nowdata->argv[i]);
		}
		free(nowdata->argv);
		free(nowdata->pids);
		temp = nowdata;
		nowdata = nowdata->next;
		free(temp);
	}
	*begin = NULL;
	return (1);
}
