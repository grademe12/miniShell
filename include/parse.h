/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:16:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/13 13:10:02 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

// init
t_token	*new_token_node(char *token, t_type type);
t_data	*new_data_node(char **ep, char **av, t_token *zt, int np);

//parse

//replace_envp
char	*get_envp(char *str, char **envp);


//
char	**mns_split(char const *s);

// utils
void	exit_error(void);
int		check_quote(char c, int *sq, int *dq, int is_escape);

#endif
