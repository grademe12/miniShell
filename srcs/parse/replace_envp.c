/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:43:04 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/29 17:05:17 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_envp_name(char *str)
{
	int		name_len;

	name_len = 0;
	while (ft_isalnum(str[name_len]) || str[name_len] == '_')
		name_len++;
	return (name_len);
}

char	*get_envp(char *str, t_data *prev)
{
	int		name_len;
	int		i;

	name_len = 0;
	if (str[0] == '$')
	{
		name_len = check_envp_name(str + 1);
		if (str[1] == '?')
			return (ft_itoa(g_signal_num));
		if (name_len == 0)
			return ("$");
		i = 0;
		while (prev->envp[i] != 0)
		{
			if (name_len && !ft_strncmp(prev->envp[i], str + 1, name_len) \
				&& (prev->envp[i])[name_len] == '=')
				return (ft_strdup((prev->envp[i]) + name_len + 1));
			i++;
		}
	}
	return (NULL);
}

void	append_replacement(char **ret, char *str, size_t len, t_data *prev)
{
	char	*temp;
	char	*new_ret;
	char	*env_val;

	temp = ft_substr(str, 0, len);
	new_ret = ft_strjoin(*ret, temp);
	free(temp);
	free(*ret);
	*ret = new_ret;
	env_val = get_envp(&str[len], prev);
	if (env_val)
	{
		new_ret = ft_strjoin(*ret, env_val);
		free(*ret);
		free(env_val);
		*ret = new_ret;
	}
}

void	replace_envp(char *str, char **ret, t_data *prev)
{
	size_t	len;
	int		sq;
	int		dq;
	int		temp;

	len = -1;
	sq = 0;
	dq = 0;
	while (str[++len])
	{
		temp = (sq || dq);
		if ((check_quote(str[len], &sq, &dq) && \
			(!temp || !(sq || dq))) || (str[len] == '$' && !sq))
		{
			append_replacement(ret, str, len, prev);
			if (str[len] == '$' && !sq)
			{
				if (str[len + 1] == '?')
					len += 1;
				else
					len += check_envp_name(str + len + 1);
			}
			str += (len) + 1;
			len = -1;
		}
	}
	append_replacement(ret, str, len, prev);
}
