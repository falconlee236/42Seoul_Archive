NAME=so_long
CFLAGS=cc -Wall -Wextra -Werror -o

SRCS=so_long.c\
	so_long_util.c\
	is_vaildpath.c

all: $(NAME)

$(NAME):
	@$(MAKE) -C mlx all
	@$(MAKE) -C libft all
	$(CFLAGS) $(NAME) $(SRCS) -L ./mlx -lmlx -framework OpenGL -framework Appkit -L ./libft -lft -g

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C mlx clean
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re