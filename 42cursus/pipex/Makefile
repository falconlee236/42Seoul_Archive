NAME=pipex
CFLAGS=cc -Wall -Wextra -Werror -o

SRCS=pipex.c\
	pipex_util.c

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft all
	$(CFLAGS) $(NAME) $(SRCS) -L ./libft -lft -g

clean:
	@$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re