/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envp_re.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:09:53 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/28 20:46:20 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ep_name_len(char *str, size_t idx)
{
	int		name_len;

	name_len = 0;
	if (str[idx + 1] == '?')
		return (1);
	while (ft_isalnum(str[idx]) || str[idx] == '_')
	{
		idx++;
		name_len++;
	}
	return (name_len);
}

char	*put_str(char *str, char *put, size_t start, size_t len)
{
	char	*ret;
	char	*temp_front;
	char	*temp_back;

	ret = ck_malloc(ft_substr(str, 0, start));
	temp_front = ck_malloc(ft_strjoin(ret, put));
	temp_back = ck_malloc(ft_substr(str, start + len, \
		ft_strlen(str) - (start + len)));
	free(ret);
	ret = ck_malloc(ft_strjoin(temp_front, temp_back));
	free(temp_front);
	free(temp_back);
	return (ret);
}

char	*get_envp(char *str, t_data *prev)
{
	size_t	len;
	char	*ep;

	len = ft_strlen(str);
	if (str[1] == '?')
		return (ft_itoa(g_signal_num));
	if (len == 1)
		return ("$");
	while (*(prev->envp))
	{
		ep = *(prev->envp);
		if (!ft_strncmp(*(prev->envp), str, len) && ep[len] == '=')
			return (ck_malloc(ft_strdup(ep + len + 1)));
		prev->envp++;
	}
	return (ck_malloc(ft_strdup("")));
}

char	*replace_envp(char *str, t_data *prev)
{
	int		idx;
	int		q_flag;
	int		*env_name;
	char	*ret;

	idx = -1;
	while (str[++idx])
	{
		q_flag = check_quote(str, idx);
		if (q_flag != 1 && str[idx] == '$')
		{
			env_name = ck_malloc(ft_substr(str, idx, ep_name_len(str, idx)));
			
		}
	}
}