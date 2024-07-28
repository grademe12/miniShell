/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:16:00 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/28 19:13:13 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	free_strarr(char ***word_arr)
{
	size_t	ind;

	ind = -1;
	while ((*word_arr)[++ind])
	{
		free((*word_arr)[ind]);
		ind++;
	}
	free(*word_arr);
	*word_arr = NULL;
	return (1);
}

int	free_token(t_token **begin)
{
	t_token	*nowtoken;
	t_token	*temp;

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
	return (1);
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
			free_token(&nowdata->zero_token);
		if (nowdata->argv)
			free_strarr(&nowdata->argv);
		temp = nowdata;
		nowdata = nowdata->next;
		free(temp);
	}
	*begin = NULL;
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
		free(nowdata->argv);
		nowdata->argv = NULL;
		temp = nowdata;
		nowdata = nowdata->next;
		free(temp);
	}
	*begin = NULL;
	return (1);
}
