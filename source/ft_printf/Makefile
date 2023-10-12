SRCS = $(shell find ./source -name '*.c')

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

LIBFT = ./libft/libft.a

all : $(LIBFT) $(NAME) 

$(LIBFT) :
	make -C ./libft

.c.o:
	gcc -c -Wall -Wextra -Werror $< -o $(<:.c=.o) -I ./libft

$(NAME) : $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

clean :
	make clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.SILENT:
.PHONY : all clean fclean re libft
