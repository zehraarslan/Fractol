NAME = fractal
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ./src/main.c ./src/fractol.c ./src/hook.c ./src/tools.c ./src/mouse_hook.c ./src/key_hook_julia.c
OBJS = $(SRCS:.c=.o)

MLX = ./miniLibx/libmlx.a
LINKS = -framework OpenGL -framework Appkit

all: $(MLX) $(NAME)

$(MLX):
	make -C miniLibx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(LINKS)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make clean -C ./miniLibx

re: fclean all

.PHONY: all clean fclean re