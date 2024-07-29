/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:36:22 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:34 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_data	*ft_datalast(t_data *data)
{
	if (data == 0)
		return (data);
	while (data->next != 0)
		data = data->next;
	return (data);
}

void	ft_dataadd_back(t_data **begin, t_data *data)
{
	if (begin == 0)
		return ;
	if (*begin == 0)
		*begin = data;
	else
		ft_datalast(*begin)->next = data;
}

void	make_data(t_data **begin, char *line, t_data *prev, int len)
{
	t_data	*newdata;
	char	**arr;
	char	*temp;
	char	*ret;
	int		idx;

	idx = -1;
	temp = ft_substr(line, 0, len - 1);
	arr = mns_split(temp);
	if (!arr)
	{
		error_unexpected_token();
		free_parse_error(begin);
		return ;
	}
	free(temp);
	while (arr[++idx])
	{
		if (!ft_strcmp(arr[idx], "~"))
			ret = ft_strdup(prev->init_homepath);
		else
		{
			ret = ft_strdup("");
			replace_envp(arr[idx], &ret, prev);
		}
		free(arr[idx]);
		arr[idx] = ret;
	}
	newdata = new_data_node(prev->envp, arr, \
		make_token(arr), prev->init_homepath);
	ft_dataadd_back(begin, newdata);
	if (!(newdata->zero_token))
		free_parse_error(begin);
}
