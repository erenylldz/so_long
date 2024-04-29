NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL
SRCS =	checker.c coordinat.c exit.c game_controller.c main.c map_check.c map.c move.c str_utils.c utils.c
OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

all: ${NAME}

$(MINI):
	make -C ./mlx &> /dev/null

$(NAME): $(MINI) $(OBJS)
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)

%.o: %.c
	${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	rm -rf ${OBJS}
	make clean -C mlx/

fclean: clean
	rm -rf ${NAME}
	make clean -C mlx/

re: fclean all
