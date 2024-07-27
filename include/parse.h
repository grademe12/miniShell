/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:16:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/26 20:43:14 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef enum e_type		t_type;

//free_struct
int		free_strarr(char **word_arr, size_t i);
int		free_token(t_token **begin);
int		free_data(t_data **begin);

// init
t_token	*new_token_node(char *token, t_type type);
t_data	*new_data_node(char **ep, char **av, t_token *zt, char *homepath);

//make_data
t_data	*ft_datalast(t_data *data);
void	ft_dataadd_back(t_data **begin, t_data *data);
void	make_data(t_data **begin, char *line, t_data *prev, int len);

//make_token
t_token	*ft_tokenlast(t_token *token);
void	ft_tokenadd_back(t_token **begin, t_token *token);
t_type	get_type(char *c);
t_token	*make_token(char **av);

//parse
void	input_num_pipe(t_data **begin, int np);
int		parsing(t_data **begin, char *line);

//replace_envp
int		check_envp_name(char *str);
char	*get_envp(char *str, t_data *prev);
void	append_replacement(char **ret, char *str, size_t len, t_data *prev);
void	replace_envp(char *str, char **ret, t_data *prev);

//split_argv
char	**mns_split(char const *s);

// utils
void	exit_error(void);
int		check_quote(char c, int *sq, int *dq);
void	free_parse_error(t_data **begin);
void	parse_error(char *token);

#endif
