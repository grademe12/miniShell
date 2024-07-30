/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:52:04 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/29 22:50:03 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# include "./Libft/libft.h"
# include "exec.h"
# include "parse.h"

// readline 관련 함수들
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_type
{
	PIPE,
	INPUT_REDIR,
	APPEND_REDIR,
	OUTPUT_REDIR,
	HEREDOC,
	CMD,
	FILENAME
}		t_type;

typedef struct s_token
{
	char			*token;
	t_type			type;
	struct s_token	*next;
}					t_token;

typedef struct s_data
{
	char			**envp;
	char			**argv;
	char			*init_homepath;
	t_token			*zero_token;
	struct s_data	*next;
	int				num_pipe;
	int				last_fd;
	char			*pwd;
}					t_data;

extern int	g_signal_num;

#endif