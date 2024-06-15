/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:55:29 by woosupar          #+#    #+#             */
/*   Updated: 2024/06/15 14:56:27 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// 입력된 문자열이 실행 가능한지??
// 절대경로, 상대경로인지 모두 확인해야함
// 파이프 기준으로 나눠서 받는게 좋을듯?
// 파이프 갯수도?
// 파이프 기준 한개의 행에서 첫 번째 문자열이 파일인지 디렉토리인지 확인
// 디렉토리라면 is a directory 출력
// 파일이라면 명령어인지 확인
// 아니라면 command not found
// 맞다면 실행 -> 분기 진입
// errno를 전역변수로? 처리 어떻게 할지?

int	check_access(t_data *data)
{
	int	i;

	if (data->envp == 0)
		return (CMD_NF);
	if (access(data->node->))
	i = 0;
	while (data->envp[i] != 0)
		if (ft_strncmp(data->envp[i], "PATH=", 5))
			break ;
	
}

int	check_dir_file(char *path)
{
	struct stat	*buf;

	if (stat(path, buf) != 0)
	{	
		strerror(errno);
		return (return_fail);
	}
	if (S_ISREG(buf->st_mode))
		return (FILE);
	if (S_ISDIR(buf->st_mode))
		return (DIR);
	return (0)
}

