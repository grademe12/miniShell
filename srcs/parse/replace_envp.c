/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:43:04 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/13 22:01:15 by sanghhan         ###   ########.fr       */
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

void	append_replacement(char **ret, char *str, size_t len, char **envp)
{
    char 	*temp;
    char 	*new_ret;
	char	*env_val;

    temp = ft_substr(str, 0, len);
    new_ret = ft_strjoin(*ret, temp);
    free(temp);
    free(*ret);
    *ret = new_ret;
	env_val = get_envp(&str[len], envp);
	if (env_val)
	{
    	new_ret = ft_strjoin(*ret, env_val);
		free(*ret);
		*ret = new_ret;
	}
}

void	replace_envp(char *str, char **ret, char **envp)
{
	size_t	len;
	int		sq;
	int		dq;
	char	*temp;
	char	*new_ret;

	len = -1;
	sq = 0;
	dq = 0;
	while (str[++len])
	{
        check_quote(str[len], &sq, &dq);
        if (str[len] == '$' && !sq) 
		{
            append_replacement(ret, str, len, envp);
            while (check_envp_name(str[len + 1]))
                len++;
            str += len + 1;
            len = -1;
		}
	}
	append_replacement(ret, str, len, envp);
}

