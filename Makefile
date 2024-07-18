CFLAGS = -Wall -Werror -Wextra
SRCS = main.c ./srcs/exec/exec.c ./srcs/exec/builtin.c ./srcs/exec/cd.c ./srcs/exec/echo.c ./srcs/exec/env_exit.c ./srcs/exec/exec.c ./srcs/exec/export.c ./srcs/exec/heredoc.c \
		./srcs/exec/make_path.c ./srcs/exec/piping.c ./srcs/exec/piping2.c ./srcs/exec/pwd.c ./srcs/exec/redirection.c ./srcs/exec/sh_lvl.c ./srcs/exec/signal.c ./srcs/exec/unset.c \
		./srcs/exec/utils.c ./srcs/exec/utils2.c
		# ./srcs/parse/ft_strip.c ./srcs/parse/init.c ./srcs/parse/make_list.c ./srcs/parse/parse.c ./srcs/parse/split_argv.c ./srcs/parse/test.c ./srcs/parse/utils.c
OBJS = $(SRCS:.c=.o)
FTDIR = ./include/Libft
NAME = minishell

all : $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I./include

$(NAME) : $(OBJS)
	make -C $(FTDIR)
	cc $(CFLAGS) -o $(NAME) $(OBJS) -I./include -L$(FTDIR) -lft -lreadline

clean :
	make -C $(FTDIR) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(FTDIR) fclean
	rm -f $(NAME)

re : fclean all