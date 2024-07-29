/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:16:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/30 05:52:41 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

# define UNEXP_TOKEN_MSG "syntax error near unexpected token"
# define UNEXP_TOKEN 258

# define UNTERM_QUOTE "syntax error unterminated quoted string"

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef enum e_type		t_type;

//free_struct
int		free_strarr(char ***word_arr);
int		free_token(t_token **begin);
void	free_parse_error(t_data **begin);
int		free_data(t_data **begin);

// init
t_token	*new_token_node(char *token, t_type type);
t_data	*new_data_node(char **ep, char **av, t_token *zt, char *homepath);

//make_data
int		make_data(t_data **begin, char *line, t_data *prev, int len);

//make_token
t_token	*make_token(char **av);

//parse
int		parsing(t_data **begin, char *line);

//replace_envp
void	replace_envp(char ***arr, t_data *prev);

//split_argv
char	**mns_split(char const *s);

// utils
void	*ck_malloc(void *ptr);
int		error(char *msg, int err);
int		check_quote(const char *str, size_t idx);

#endif
