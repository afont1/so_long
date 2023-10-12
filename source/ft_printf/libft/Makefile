SRCS = $(shell find ./ -name '*.c')

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

NAME = libft.a

RM = rm -f

all : $(NAME)

.c.o:
	gcc -c -Wall -Wextra -Werror $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_B)
	ar rc $(NAME) $(OBJS) $(OBJS_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

rebonus : fclean bonus

.SILENT:
.PHONY: all clean fclean re bonus
