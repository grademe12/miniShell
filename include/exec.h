/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:47:37 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/23 00:29:23 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

// int	exec(void);
// int	check_builtin();
// int	exe_builtin(int val);
// int	echo_builtin(struct *something);

# define return_fail -10
# define CMD_NF -15
# define FILE -300
# define DIR -301
# define HEREDOC_MAX 65536

typedef enum e_type
{
	INPUT_REDIR,
	APPEND_REDIR,
	OUTPUT_REDIR,
	HEREDOC,
	CMD
}			t_type;

typedef struct s_token
{
	char			*token; // 각 토큰
	t_type			type; // 타입
	struct s_token	*next; // 연결리스트 다음 노드 (다음 토큰)
}					t_token;

typedef struct s_data
{
	char			**envp; // main에서 받는 환경변수
	char			**argv; // 파이프 기준으로한 한 구문의 이차원 문자열 배열
	t_token			*zero_token; // =argv[0], 구문의 첫 번째 토큰
	struct s_data	*next; // data 연결리스트 다음 노드 (다음 구문)
	int				num_pipe; // 파이프 갯수 = 구문 갯수 - 1
	pid_t			*pids; // 자식프로세스 pid 배열
}					t_data;

int		is_path(char *str);
void	inner_function_error(char *str);
int		strerror_errno(int errno);
int		ft_errnum(int errnum_input);

#endif