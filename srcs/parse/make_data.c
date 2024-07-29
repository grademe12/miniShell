/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:36:22 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 05:34:19 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_data	*ft_datalast(t_data *data)
{
	if (data == 0)
		return (data);
	while (data->next != 0)
		data = data->next;
	return (data);
}

static void	ft_dataadd_back(t_data **begin, t_data *data)
{
	if (begin == 0)
		return ;
	if (*begin == 0)
		*begin = data;
	else
		ft_datalast(*begin)->next = data;
}

int	make_data(t_data **begin, char *line, t_data *prev, int len)
{
	t_data	*newdata;
	char	**arr;
	char	*ret;
	char	*pipe;
	int		idx;

	idx = -1;
	pipe = ck_malloc(ft_substr(line, 0, len));
	arr = mns_split(pipe);
	free(pipe);
	if (!arr)
	{
		free_data(begin);
		error(UNEXP_TOKEN_MSG, UNEXP_TOKEN);
		return (0);
	}
	replace_envp(&arr, prev);
	check_arr(&arr);
	newdata = new_data_node(prev->envp, arr, \
		make_token(arr), prev->init_homepath);
	ft_dataadd_back(begin, newdata);
	if (!(newdata->zero_token))
		free_data(begin);
	return (1);
}
