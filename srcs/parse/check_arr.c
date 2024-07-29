/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 03:53:38 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 05:06:38 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	arr_len(char **arr)
{
	int	arr_len;
	int	i;

	arr_len = 0;
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0])
			arr_len++;
	}
	return (arr_len);
}

static void	remove_qoute(char *str)
{
	int		dup_i;
	int		new_i;
	int		q_flag;
	int		prev_q_flag;
	char	*dup;

	dup = ck_malloc(ft_strdup(str));
	dup_i = -1;
	new_i = 0;
	q_flag = 0;
	while (dup[++dup_i])
	{
		prev_q_flag = q_flag;
		q_flag = check_quote(dup, dup_i);
		if (!((!q_flag && prev_q_flag) || (q_flag && !prev_q_flag)))
			continue ;
		str[new_i] = dup[dup_i];
		new_i++;
	}
	str[new_i] = '\0';
	free(dup);
}

void	check_arr(char ***arr)
{
	int		new_arr_i;
	int		arr_i;
	int		len;
	char	**new_arr;

	if (!(*arr)[0][0] && !(*arr)[1])
	{
		free_strarr(arr);
		return ;
	}
	len = arr_len(*arr);
	new_arr = ck_malloc(malloc(arr_len(*arr) * sizeof(char *) + 1));
	new_arr_i = -1;
	arr_i = 0;
	while (++new_arr_i < arr_len(*arr))
	{
		if (!(*arr)[arr_i][0])
			arr_i++;
		remove_qoute((*arr)[arr_i]);
		new_arr[new_arr_i] = ck_malloc(ft_strdup((*arr)[arr_i]));
		arr_i++;
	}
	new_arr[new_arr_i] = NULL;
	free_strarr(arr);
	*arr = new_arr;
}
