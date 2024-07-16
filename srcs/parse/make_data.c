/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:36:22 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/16 20:12:22 by sanghhan         ###   ########.fr       */
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

void	make_data(t_data **begin, char *line, char **ep, int len)
{
	t_data	*newdata;
	char	**arr;
	char	*temp;
	char	*ret;
	int		idx;

	idx = -1;
	temp = ft_substr(line, 0, len - 1);
	arr = mns_split(temp);
	free(temp);
	while (arr[++idx])
	{
		ret = ft_strdup("");
		replace_envp(arr[idx], &ret, ep);
		free(arr[idx]);
		arr[idx] = ret;
	}
	newdata = new_data_node(ep, arr, make_token(arr), 0);
	ft_dataadd_back(begin, newdata);
}
