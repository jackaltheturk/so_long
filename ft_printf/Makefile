NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
SRCS = ft_printf.c ft_tools.c ft_hexa.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar  rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	
fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re