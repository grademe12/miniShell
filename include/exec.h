/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:47:37 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/23 16:52:12 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define RET_FAIL -10
# define CMD_NF -15
# define FILETYPE -300
# define DIR -301

# include "minishell.h"

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef enum e_type		t_type;
// 빌트인 리다이렉션 후 실행
int		builtin_red_exe(t_data *data, int val);

// 빌트인 CD
char	*get_home_path(t_data *data);
int		change_env_pwd(t_data *data, char *str);
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
int		check_builtin(char *cmd);
int		exe_builtin(t_data *data, int val);
int		builtin_loop(t_data *data);
char	*err_get_cmd(int val);

// 히어독 함수
char	*multi_heredoc(char *str);
char	*heredoc_init(void);
int		rm_heredoc(void);
int		heredoc_red(t_token *cur);

// 절대경로로 경로 확장
char	*make_path(char **argv, char **envp);
int		cannot_find(char **path_split, char **argv, int i);

// 파이프 연결
int		piping(t_data *data);
int		make_child(t_data *data, int i, int *old_fd, int *new_fd);
int		child_working(t_data *data, int *old_fd, int *new_fd, int i);
int		dup_fd(t_data *data, int *old_fd, int *new_fd, int i);
int		check_cmd_valid(t_data *data, int *old_fd, int *new_fd, int i);
int		last_child(t_data *data, int i, int *old_fd, int *new_fd);
int		child_wait(t_data *data, int i, pid_t pid, int *old_fd);

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
int		is_path(char *str);
void	inner_function_error(char *str);
int		strerror_errno(int err);
int		child_err_exit(int err);
int		remake_argv(t_data *data);
int		check_dir_file(char *path);
int		find_equals(char *str);
int		print_err_check_num(int check_num, char *str);
void    envp_alloc(t_data *data, char **envp);

// 쉘레벨 함수
int		increase_shlvl(t_data *data);
int		decrease_shlvl(t_data *data);

// signal
void	sigint_handler(int sig, t_data *data);
void	sigeof_handler(int sig);
void	sigquit_handler(int sig);

#endif