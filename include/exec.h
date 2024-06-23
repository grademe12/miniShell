/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:47:37 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/23 17:04:46 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

# define return_fail -10
# define CMD_NF -15
# define FILETYPE -300
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

// 빌트인 리다이렉션 후 실행
int	builtin_red_exe(t_data *data, int val);

// 빌트인 CD
char	*get_home_path(t_data *data);
int		make_oldpwd(t_data *data);
int		cd_builtin2(t_data *data);
int		cd_builtin(t_data *data);

// 빌트인 ECHO
int		echo_builtin(t_data *data);

// 빌트인 ENV EXIT
int		env_builtin(t_data *data);
int		exit_builtin(t_data *data);

// 빌트인 EXPORT
int		export_builtin(t_data *data);
int		print_env_declare(t_data *data);
int		check_dup(t_data *data, char *str, int eq_index);
int		do_export(t_data *data, char *str, int eq_index);
int		ft_realloc(t_data *data);

// 실행 도입부 함수
int		exec(t_data *data);
int		check_builtin(t_data *data);
int		exe_builtin(t_data *data, int val);

// 히어독 함수
char	*multi_heredoc(char *str);
char	*heredoc_init(void);
int		rm_heredoc(void);
int		heredoc_red(t_token *cur);

// 절대경로로 경로 확장
char	*make_path(char **argv, char **envp);
int		cannot_find(char **path_split, char **argv);

// 파이프 연결
int		piping(t_data *data);
int		make_child(t_data *data, int i, int **old_fd);
int		child_working(t_data *data, int **old_fd, int *new_fd);
int		dup_fd(t_data *data, int **old_fd, int *new_fd);
int	last_child(t_data *data, int i, int **old_fd);

// 빌트인 PWD
int		pwd_builtin(t_data *data);

// 리다이렉션 함수
int		input_red(t_token *cur, int type);
int		open_type(char *filename, int type);
int		red_dup(int fd, int type);
int		check_red(t_data *data, t_token *cur);

// 빌트인 UNSET
int		unset_builtin(t_data *data);
int		pull_envp(t_data *data, int idx);
int		find_unset(t_data *data, char *target);
int		remake_envp(t_data *data);

// 유틸 함수
int		ft_errnum(int errnum_input);
int		is_path(char *str);
void	inner_function_error(char *str);
int		strerror_errno(int errno);
int		child_err_exit(char *str);
int		remake_argv(t_data *data);
int		check_cmd_valid(t_data *data, int **old_fd, int *new_fd);
int		check_dir_file(char *path);
int		find_equals(char *str);

// 쉘레벨 함수
int		increase_shlvl(t_data *data);
int		decrease_shlvl(t_data *data);

#endif