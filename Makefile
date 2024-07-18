CFLAGS = -Wall -Werror -Wextra
SRCS = main.c ./srcs/exec/exec.c
OBJS = $(SRCS:.c=.o)
FTDIR = ./include/Libft
NAME = minishell

$(NAME) : $(OBJS)
	make -C $(FTDIR)
	cc $(CFLAGS) -o $(NAME) $(OBJS) -I./include -L$(FTDIR) -lft -lreadline

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I./include

all : $(NAME)

clean :
	make -C $(FTDIR) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(FTDIR) fclean
	rm -f $(NAME)

re : fclean all