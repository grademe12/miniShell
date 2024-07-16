/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:34:47 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/16 20:30:02 by sanghhan         ###   ########.fr       */
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
	t_data	*data;
	t_data	*nowdata;

	(void) ac;
	(void) av;
	(void) ep;
	line = readline("input$ ");
	data = parsing(line, ep);
	nowdata = data;
	while (nowdata)
	{
		printf("=======+++===\n");
		printf("[arr]\n");
		print_arr(nowdata->argv);
		printf("[token]\n");
		if (nowdata->zero_token)
		{
			printf("%s\n", nowdata->zero_token->token);
			printf("type : %d\n", nowdata->zero_token->type);
		}
		else
			printf("NULL\n");
		printf("[num_pipe] : %d\n\n", nowdata->num_pipe);
		nowdata = nowdata->next;
	}
    return (0);
}
