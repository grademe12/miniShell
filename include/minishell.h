/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghhan <sanghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:52:04 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/07 16:54:46 by sanghhan         ###   ########.fr       */
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
	CMD
}		t_type;

/*
typedef struct s_token
{
	char			*token; // 각 토큰
	t_type			type; // 타입
	struct s_token	*next; // 연결리스트 다음 노드 (다음 토큰)
}					t_token;
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
	t_token			*zero_token;
	struct s_data	*next;
	int				num_pipe;
	pid_t			*pids;
}					t_data;

#endif