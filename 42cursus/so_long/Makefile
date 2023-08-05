NAME=so_long
CFLAGS=cc -Wall -Wextra -Werror -o

SRCS=so_long.c\
	is_vaildmap.c\
	is_vaildpath.c\
	is_vaildutil.c\
	make_enemy.c\
	so_longutil.c\
	hook_event.c\
	loop_hook_event.c\
	check_filename.c

all: $(NAME)

$(NAME):
	@$(MAKE) -C mlx all
	@$(MAKE) -C libft all
	$(CFLAGS) $(NAME) $(SRCS) -L ./mlx -lmlx -framework OpenGL -framework Appkit -L ./libft -lft

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C mlx clean
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re