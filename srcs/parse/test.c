/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:34:47 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/13 22:06:20 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"
# include <stdio.h>

void	print_arr(char	**arr)
{
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}

int	ft_lenarr(char	**arr)
{
	int	i;

	i = 0;
	while (*arr++)
		i++;
	return (i);
}

static int	do_free(char **word_arr, size_t i)
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

int	main(int ac, char **av, char **ep)
{
	char 	*line;
	char	**arr;
	int		idx = -1;
	char	*ret;
	char	*temp;

	(void) ac;
	(void) av;
	(void) ep;
	line = readline("input$ ");
	arr = mns_split(line);
	while (arr[++idx])
	{
		ret = ft_strdup("");
		replace_envp(arr[idx], &ret, ep);
		free(arr[idx]);
		arr[idx] = ret;
	}
	print_arr(arr);
	do_free(arr, ft_lenarr(arr));
    return (0);
}
