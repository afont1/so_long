SRCS =	$(shell find ./source -name '*.c') \
		$(shell find ./GNL -name '*.c') \
		$(shell find ./ft_printf -name '*.c')

SRCS_B = $(shell find ./source_b -name '*.c') \
		$(shell find ./GNL -name '*.c') \
		$(shell find ./ft_printf -name '*.c')

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = ft_printf/libftprintf.a

NAME = so_long

NAME_B = so_long_b

INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS)
	make -C ft_printf --no-print-directory
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) $(MLX_FLAGS) -o $(NAME)
	echo "   \033[37;42;1m$(NAME) created\033[0m"

clean:
	make clean -C ft_printf --no-print-directory
	rm -rf $(OBJS) $(OBJS_B)
	echo "   \033[41;1mObject file deleted\033[0m"

fclean: clean
	make fclean -C ft_printf --no-print-directory
	rm -rf $(NAME) $(NAME_B)
	echo "   \033[41;1m$(NAME) deleted\033[0m"

re: fclean all

$(NAME_B): $(OBJS_B)
	make -C ft_printf --no-print-directory
	$(CC) $(CFLAGS) $(OBJS_B) $(INCLUDES) $(LIB) $(MLX_FLAGS) -o $(NAME_B) -lm
	echo "   \033[37;42;1m$(NAME) bonus created\033[0m"

.SILENT:
.PHONY: all clean fclean re bonus

#MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
#INCLUDES = -I/opt/X11/include -Imlx