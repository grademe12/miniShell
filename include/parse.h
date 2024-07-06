/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:16:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/06 20:16:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

typedef struct s_node	t_node;
typedef enum e_type		t_type;

enum e_type
{
	PIPE,
	INPUT_REDIR,
	APPEND_REDIR,
	OUTPUT_REDIR,
	HEREDOC,
	CMD
};

struct s_node
{
	char	*cmd;
	char	**argv;
	t_type	type;
	t_node	*next;
};

//ft_strip
int			ft_strip(char	**str);

//init
void		init_node(t_node *node);

//make_list
t_node		*make_node(char *line, size_t start, size_t end);
t_node		*addnode_back(t_node *begin, t_node *node);
t_node		*parse(void);

//parse
int			check_quote(char c, int *single_quote, int *double_quote);
int			meet_redir(char *line, size_t *start, size_t *end, t_node *begin);
int			meet_pipe(char *line, size_t *start, size_t *end, t_node *begin);
t_node		*make_list(char *line, t_node *begin);

//split_argv
char		**ft_split(char const *s);
t_type		get_type(char *c);

//utils
void		exit_error(void);

#endif
