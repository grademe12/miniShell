/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:34:47 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/07 18:26:06 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

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

int	main(int ac, char **av)
{
	int		i;
	char	**arr;

	i = 1;
	while (i < ac)
	{
		arr = mns_split(av[i], '|');
		print_arr(arr);
		do_free(arr, ft_lenarr(arr));
		i++;
	}
}
