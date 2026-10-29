# miniShell

bash의 핵심 동작을 C로 다시 만든 셸입니다. 42서울 2인 과제로, 파싱은 팀원([sanghhan](https://github.com/sanghhan))이, 실행부는 제가 맡았습니다. (2024.06 – 2024.08)

포트폴리오 설명: <https://woosupar.dev/projects/minishell/>

## 지원하는 것

| 기능 | 내용 |
|---|---|
| 명령 실행 | `PATH` 탐색, `fork`, `execve`, `waitpid`, 종료 코드를 `$?`로 저장 |
| 파이프 | `cmd1 \| cmd2 \| cmd3`, `pipe`와 `dup2`로 연결 |
| 리다이렉션 | `<`, `>`, `>>` |
| heredoc | `<<`, 여러 개일 때는 마지막 것이 표준 입력 |
| 빌트인 | `cd`, `pwd`, `echo -n`, `export`, `unset`, `env`, `exit` |
| 시그널 | `Ctrl-C`, `Ctrl-\`, `Ctrl-D`를 프롬프트와 자식 프로세스에서 bash처럼 처리 |
| 환경변수 | `$VAR`, `$?` 확장, `SHLVL` 증가 |

## 빌드와 실행

readline 라이브러리가 필요합니다.

```bash
make
./minishell
```

프롬프트는 `bfsh$ `입니다.

## 구조

```
srcs/
  parse/   입력을 토큰으로 나누고 명령 단위로 묶기 (팀원)
  exec/    실행부 (제가 맡은 부분)
    exec, make_path      PATH 탐색과 명령 실행
    piping, redirection  파이프와 리다이렉션
    heredoc              heredoc 입력 처리
    cd, pwd, echo, export, unset, env, exit   빌트인
    signal_main, signal_child                 프롬프트와 자식 프로세스의 시그널
    sh_lvl               SHLVL 처리
include/   헤더와 Libft(42 과제용 기본 함수 모음)
main.c     프롬프트(bfsh$) 루프
```

## 구현하며 신경 쓴 점

- **셸 상태를 바꾸는 빌트인은 셸 프로세스에서 실행합니다.** `cd`, `export`, `unset`, `exit`를 자식 프로세스에서 돌리면 셸 자신에게 반영되지 않습니다. 단, 파이프라인 안에서는 bash처럼 자식에서 실행합니다.
- **heredoc이 여러 개일 때.** 모두 입력은 받되 마지막 것만 표준 입력이 되도록 맞췄습니다. 가장 오래 붙잡은 부분입니다.
- **현재 디렉터리가 지워졌을 때.** 다른 셸에서 현재 디렉터리를 지운 뒤 `cd`나 `pwd`를 하면 `getcwd`가 실패합니다. 이 경우를 bash와 같은 출력으로 맞췄습니다.
- **파일 디스크립터와 메모리.** 리다이렉션과 파이프에서 연 fd를 닫고, `export` 이중 해제 같은 메모리 문제를 정리했습니다.
