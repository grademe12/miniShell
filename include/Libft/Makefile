CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strcmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_pf_address.c ft_pf_char.c ft_pf_dec.c ft_pf_int.c ft_pf_low_hex.c \
		ft_pf_per.c ft_pf_str.c ft_pf_unsigned_dec.c ft_pf_upp_hex.c ft_printf.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c ft_strjoin_pipe.c \
		ft_freesplit.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
		ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all : $(NAME)


$(OBJS) : $(SRCS)
	@$(CC) $(CFLAGS) -I libft.h -c $(SRCS)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo libft compiled

clean :
	@rm -f $(OBJS) bonus

fclean : clean
	@rm -f $(NAME)

re : fclean all
