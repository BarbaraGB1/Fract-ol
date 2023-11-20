NAME = fractol
SRC = main.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx
RM = rm -rf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

TARGET = all

all = $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(SRC) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make bonus -C $(LIBFT_DIR)

clean:
		$(RM) $(OBJ) fractol.dSYM ./fractol
		$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) $(TARGET)

.PHONY: re fclean clean all new
		

