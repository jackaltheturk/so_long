NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS= -lm -lX11 -lXext
LIBFT = libft/libft.a
BONUS = 
SRC = src/so_long.c src/gnl.c src/error.c \
src/pic_loader.c src/mapchecker.c \
src/maphandler.c src/action.c src/moves.c \

BONUS_SRC = 

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
	
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBS) libmlx.a

$(BONUS): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ) $(LIBFT)

bonus : $(BONUS)

$(LIBFT):
	make -C libft/

all: $(NAME) bonus

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f checker
	make fclean -C libft/

re: fclean $(NAME)

re_bonus: fclean bonus

.PHONY: all clean fclean re