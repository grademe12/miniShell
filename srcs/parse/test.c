/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:34:47 by sanghhan          #+#    #+#             */
/*   Updated: 2024/06/16 02:47:04 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
		arr = ft_split(av[i]);
		do_free(arr, ft_lenarr(arr));
	}
}
