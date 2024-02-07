CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIB = -lreadline

NAME = minishell
SRCS = main.c util.c util2.c util3.c \
		$(wildcard built_in/*.c) \
		$(wildcard cmd_exec/*.c) \
		$(wildcard cmd_list/*.c) \
		$(wildcard lexical_analysis/*.c) \
		$(wildcard syntax_analysis/*.c) \
		$(wildcard sig_handle/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft all
	$(CC) $(CFLAGS) $(CLIB) $(OBJS) -o $(NAME) -L ./libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all re clean fclean
