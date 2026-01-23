CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

NAME = pipex

SRCS = cmd.c main.c

OBJS = $(SRCS:.c=.o)

LIBFT   = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re