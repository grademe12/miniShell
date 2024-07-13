/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:34:47 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/13 13:26:35 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

// void	print_arr(char	**arr)
// {
// 	while (*arr)
// 	{echp
// 		printf("%s\n", *arr);
// 		arr++;
// 	}
// }

// int	ft_lenarr(char	**arr)
// {
// 	int	i;

// 	i = 0;
// 	while (*arr++)
// 		i++;
// 	return (i);
// }

// static int	do_free(char **word_arr, size_t i)
// {
// 	size_t	ind;

// 	ind = 0;
// 	while (ind <= i)
// 	{
// 		free(word_arr[ind]);
// 		ind++;
// 	}
// 	free(word_arr);
// 	return (1);
// }

int	main(int ac, char **av, char **ep)
{
    char *var = "$VSCODE";
    char *value = get_envp(var, ep);
    if (value) 
        printf("Value of %s: %s\n", var, value);
	else 
        printf("%s not found\n", var);

    return (0);
}
