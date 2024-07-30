CFLAGS = -Wall -Werror -Wextra
SRCS = main.c \
		./srcs/exec/exec.c ./srcs/exec/cd.c \
		./srcs/exec/echo.c ./srcs/exec/env.c ./srcs/exec/exit.c \
		./srcs/exec/export.c ./srcs/exec/heredoc.c \
		./srcs/exec/make_path.c ./srcs/exec/piping.c ./srcs/exec/piping2.c \
		./srcs/exec/pwd.c ./srcs/exec/redirection.c ./srcs/exec/sh_lvl.c \
		./srcs/exec/signal.c ./srcs/exec/unset.c \
		./srcs/exec/utils.c ./srcs/exec/utils2.c ./srcs/exec/utils3.c \
		./srcs/exec/signal_child.c ./srcs/exec/signal_main.c \
		./srcs/parse/init.c ./srcs/parse/check_arr.c\
		./srcs/parse/parse.c ./srcs/parse/split_argv.c \
		./srcs/parse/utils.c ./srcs/parse/make_data.c ./srcs/parse/make_token.c \
		./srcs/parse/replace_envp.c ./srcs/parse/free_struct.c
OBJS = $(SRCS:.c=.o)
FTDIR = ./include/Libft
NAME = minishell

$(NAME) : $(OBJS)
	@make -C $(FTDIR)
	@cc -g $(CFLAGS) -o $(NAME) $(OBJS) -I./include -L$(FTDIR) -lft -lreadline -fsanitize=address 
	@echo bfsh compiled

%.o: %.c
	@cc -g $(CFLAGS) -c $< -o $@ -I./include

all : $(NAME)

clean :
	@make -C $(FTDIR) clean
	@rm -f $(OBJS)
	@echo clean done

fclean : clean
	@make -C $(FTDIR) fclean
	@rm -f $(NAME)
	@echo fclean done

re : fclean all
