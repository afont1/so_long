SRCS =	$(shell find ./source -name '*.c')

SRCS_B = $(shell find ./source_b -name '*.c')

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = source/ft_printf/libftprintf.a

NAME = so_long

INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME) 

$(NAME): $(OBJS)
	make -C source/ft_printf --no-print-directory
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) $(MLX_FLAGS) -o $(NAME)
	echo "   \033[37;42;1m$(NAME) created\033[0m"

clean:
	make clean -C source/ft_printf --no-print-directory
	rm -rf $(OBJS) $(OBJS_B)
	echo "   \033[41;1mObject file deleted\033[0m"

fclean: clean
	make fclean -C source/ft_printf --no-print-directory
	rm -rf so_long so_long_b
	echo "   \033[41;1m$(NAME) deleted\033[0m"

re: fclean all

bonus: $(OBJS) $(OBJS_B)
	make -C source/ft_printf --no-print-directory
	$(CC) $(CFLAGS) $(OBJS_B) $(OBJS) $(INCLUDES) $(LIB) $(MLX_FLAGS) -o $(NAME)
	echo "   \033[37;42;1m$(NAME) bonus created\033[0m"

.SILENT:
.PHONY: all clean fclean re bonus

#MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
#INCLUDES = -I/opt/X11/include -Imlx