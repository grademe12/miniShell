/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:43:04 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/13 00:26:45 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_envp_name(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char	*get_envp(char *str, char **envp)
{
	int		name_len;
	char	*ret;

	name_len = 0;
	if (str[0] == '$')
	{
		while (check_envp_name(str[name_len + 1]))
			name_len++;
		while (*envp)
		{
			if (name_len && !ft_strncmp(*envp, str + 1, name_len) \
				&& (*envp)[name_len] == '=')
				return (*envp + name_len + 1);
			envp++;
		}
	}
	return (NULL);
}

char	*parse_string(char *str, char **envp)
{
	char	*ret;
	int		idx;
	int		sq;
	int		dq;
	int		is_escape;

	ret = ft_strdup("");
	idx = -1;
	sq = 0;
	dq = 0;
	is_escape = 0;
	while (str[++idx])
	{
		if (str[idx] == '\\' && !is_escape)
		{
			is_escape = 1;
			continue ;
		}
		check_quote(str[idx], &sq, &dq, is_escape);
	}
}
