/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:26:30 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/23 00:26:47 by woosupar         ###   ########.fr       */
=======
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:57:56 by sanghhan          #+#    #+#             */
/*   Updated: 2024/06/16 03:39:10 by sanghhan         ###   ########.fr       */
>>>>>>> 58208751a5ea28989e9aa7e9ef348a5e81b6d73f
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
<<<<<<< HEAD
 #define PARSE_H

 #endif
=======
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
>>>>>>> 58208751a5ea28989e9aa7e9ef348a5e81b6d73f
