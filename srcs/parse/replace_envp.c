/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:43:04 by sanghhan          #+#    #+#             */
/*   Updated: 2024/07/30 07:31:17 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_envp_name(char *str)
{
	int		name_len;

	name_len = 0;
	if (str[name_len] == '?')
		return (1);
	while (ft_isalnum(str[name_len]) || str[name_len] == '_')
		name_len++;
	return (name_len);
}

static char	*get_envp(char *str, size_t start, t_data *prev)
{
	int	name_len;
	int	i;

	name_len = 0;
	if (str[start] == '$')
	{
		name_len = check_envp_name(str + start + 1);
		if (str[start + 1] == '?')
			return (ck_malloc(ft_itoa(g_signal_num)));
		if (name_len == 0)
			return (ck_malloc(ft_strdup("$")));
		i = -1;
		while (prev->envp[++i])
		{
			if (!ft_strncmp(prev->envp[i], str + start + 1, name_len) \
				&& (prev->envp[i])[name_len] == '=')
				return (ck_malloc(ft_strdup((prev->envp[i]) + name_len + 1)));
		}
	}
	return (ck_malloc(ft_strdup("")));
}

static void	append_rep(char *str, char *envp, char **ret, size_t len)
{
	char	*temp;
	char	*new_ret;

	temp = ck_malloc(ft_substr(str, 0, len));
	new_ret = ck_malloc(ft_strjoin(*ret, temp));
	free(temp);
	free(*ret);
	*ret = new_ret;
	if (envp)
	{
		new_ret = ck_malloc(ft_strjoin(*ret, envp));
		free(*ret);
		*ret = new_ret;
	}
}

static char	*replace_string(char *str, t_data *prev)
{
	int		i;
	int		start;
	char	*envp;
	char	*ret;

	i = -1;
	start = 0;
	ret = ck_malloc(ft_strdup(""));
	envp = NULL;
	while (str[++i])
	{
		if ((str[i] == '$') && check_quote(str, i) != 1)
		{
			envp = get_envp(str, i, prev);
			append_rep(str + start, envp, &ret, i - start);
			free(envp);
			envp = NULL;
			i += check_envp_name(str + i + 1) + 1;
			start = i;
		}
	}
	append_rep(str + start, envp, &ret, i - start);
	return (ret);
}

void	replace_envp(char ***arr, t_data *prev)
{
	int		i;
	char	*str;

	i = -1;
	while ((*arr)[++i])
	{
		if (!ft_strcmp((*arr)[i], "~"))
		{
			str = get_envp("HOME", 0, prev);
			if (!str[0])
			{
				free(str);
				str = ck_malloc(ft_strdup(prev->init_homepath));
			}
		}
		else
			str = replace_string((*arr)[i], prev);
		free((*arr)[i]);
		(*arr)[i] = str;
	}
}
