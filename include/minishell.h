/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:52:04 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:26 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* printf */
# include <stdio.h>
/* 
	readline, rl_clear_history, rl_on_new_line, 
	rl_replace_line, rl_redisplay, add_history 
*/
# include <readline/readline.h>
# include <readline/history.h>
/* malloc, free */
# include <stdlib.h>
/* 
	write, access, read, close, fork, 
	wait, waitpid, wait3, wait4, 
	signal, kill, exit, 
	dup, dup2, pipe, isatty, ttyname, ttyslot 
*/
# include <unistd.h>
/* open */
# include <fcntl.h>
/* sigaction, sigemptyset, sigaddset */
# include <signal.h>
/* gextcwd, chdir */
# include <unistd.h>
/* stat, lstat, fstat */
# include <sys/stat.h>
/* unlink */
# include <unistd.h>
/* execve */
# include <unistd.h>
/* opendir, readdir, closedir */
# include <dirent.h>
/* strerror, perror */
# include <string.h>
/* ioctl */
# include <sys/ioctl.h>
/* getenv */
# include <stdlib.h>
/* tcsetattr, tcgetattr */
# include <termios.h>
/* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs */
# include <curses.h>
# include <term.h>

typedef enum e_type
{
	PIPE,
	INPUT_REDIR,
	APPEND_REDIR,
	OUTPUT_REDIR,
	HEREDOC,
	CMD
}		t_type;

/*
	char			*token; // 각 토큰
	t_type			type; // 타입
	struct s_token	*next; // 연결리스트 다음 노드 (다음 토큰)
*/
typedef struct s_token
{
	char			*token;
	t_type			type;
	struct s_token	*next;
}					t_token;

/*
	char			**envp; --> main에서 받는 환경변수
	char			**argv; --> 파이프 기준으로한 한 구문의 이차원 문자열 배열
	t_token			*zero_token; --> =argv[0], 구문의 첫 번째 토큰
	struct s_data	*next; --> data 연결리스트 다음 노드 (다음 구문)
	int				num_pipe; --> 파이프 갯수 = 구문 갯수 - 1
	pid_t			*pids; --> 자식프로세스 pid 배열
*/
typedef struct s_data
{
	char			**envp;
	char			**argv;
	char			*init_homepath;
	t_token			*zero_token;
	struct s_data	*next;
	int				num_pipe;
	pid_t			*pids;
}					t_data;

# include "./Libft/libft.h"
# include "exec.h"
# include "parse.h"

// readline 관련 함수들
# include <readline/readline.h>
# include <readline/history.h>

extern volatile sig_atomic_t signal_num;

#endif