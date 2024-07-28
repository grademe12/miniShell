/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:43:04 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/28 20:44:04 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_envp_name(char *str)
{
	int		name_len;

	name_len = 0;
	if (str[1] == '?')
		return (1);
	while (ft_isalnum(str[name_len]) || str[name_len] == '_')
		name_len++;
	return (name_len);
}

char	*get_envp(char *str, t_data *prev)
{
	int		name_len;

	name_len = 0;
	if (str[0] == '$')
	{
		name_len = check_envp_name(str + 1);
		if (str[1] == '?')
			return (ft_itoa(g_signal_num));
		if (name_len == 0)
			return ("$");
		while (*(prev->envp))
		{
			if (name_len && !ft_strncmp(*(prev->envp), str + 1, name_len) \
				&& (*(prev->envp))[name_len] == '=')
				return (ft_strdup(*(prev->envp) + name_len + 1));
			(prev->envp)++;
		}
	}
	return (NULL);
}

char	*append_replacement(char *str, char *ret, size_t len, t_data *prev)
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

char	*replace_envp(char *str, t_data *prev)
{
	size_t	idx;
	int		temp;
	int		q_flag;
	char	*ret;

	idx = -1;
	ret = ft_strdup("");
	while (str[++idx])
	{
		q_flag = check_quote(str, idx);
		if (str[idx] == '$' && q_flag != 1)
		{
			append_replacement(str, idx, prev);
			if (str[idx] == '$' && !sq)
			{
				if (str[idx + 1] == '?')
					idx += 1;
				else
					idx += check_envp_name(str + len + 1);
			}
			idx ++;
		}
	}
	append_replacement(ret, str, len, prev);
}
