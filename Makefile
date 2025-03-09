NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS= -lm -lX11 -lXext
LIBFT = libft/libft.a
LIBMLX = minilibx-linux/libmlx.a
FT_PRINTF = ft_printf/libftprintf.a
SRC = src/gnl.c src/so_long.c src/error.c \
src/pic_loader.c src/mapchecker.c \
src/maphandler.c src/action.c src/moves.c \

OBJ = $(SRC:.c=.o)
	
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(LIBMLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF) $(LIBMLX) $(LIBS) 

$(LIBFT):
	make -C libft/

$(FT_PRINTF):
	make -C ft_printf/

$(LIBMLX):
	make -C minilibx-linux/

all: $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft/
	make clean -C ft_printf/
	
fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	make fclean -C ft_printf/

re: fclean $(NAME)

.PHONY: all clean fclean re