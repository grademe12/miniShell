/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:16:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/18 18:10:40 by sanghhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

// init
t_token	*new_token_node(char *token, t_type type);
t_data	*new_data_node(char **ep, char **av, t_token *zt, int np);

//make_data
t_data	*ft_datalast(t_data *data);
void	ft_dataadd_back(t_data **begin, t_data *data);
void	make_data(t_data **begin, char *line, char **ep, int len);

//make_token
t_token	*ft_tokenlast(t_token *token);
void	ft_tokenadd_back(t_token **begin, t_token *token);
t_type	get_type(char *c);
t_token	*make_token(char **av);

//parse
void	input_num_pipe(t_data **begin, int np);
t_data	*parsing(t_data **begin, char *line, char **envp);

//replace_envp
int		check_envp_name(char c);
char	*get_envp(char *str, char **envp);
void	append_replacement(char **ret, char *str, size_t len, char **envp);
void	replace_envp(char *str, char **ret, char **envp);

//split_argv
char	**mns_split(char const *s);

// utils
void	exit_error(void);
int		check_quote(char c, int *sq, int *dq);

#endif
