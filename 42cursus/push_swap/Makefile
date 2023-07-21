CFLAGS = gcc -Wall -Wextra -Werror -o
NAME = push_swap
NAME2 = checker
 
SRC = 	push_swap.c\
		parse_input.c\
		deque_function_1.c\
		deque_function_2.c\
		push-shift_command.c\
		rotate_command.c\
		rev_rotate_command.c\
		small_number.c\
		pre_processing.c\
		sand_clock.c

 SRC2 =	checker_bonus.c\
		parse_input_bonus.c\
		deque_function_1_bonus.c\
		deque_function_2_bonus.c\
		push-shift_command_bonus.c\
		rotate_command_bonus.c\
		rev_rotate_command_bonus.c

all: $(NAME)

bonus: $(NAME2)

$(NAME):
	@$(MAKE) -C libft/ all
	$(CFLAGS) $(NAME) $(SRC) -L libft/ -lft

$(NAME2):
	@$(MAKE) -C libft/ bonus
	$(CFLAGS) $(NAME2) $(SRC2) -L libft/ -lft

clean:
	@$(MAKE) -C libft/ clean

fclean: fclean
	rm -f $(NAME)
	rm -f $(NAME2)
	@$(MAKE) -C libft/ fclean

re: fclean all
.PHONY: all clean fclean re