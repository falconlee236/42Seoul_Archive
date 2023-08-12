NAME=pipex
CFLAGS=cc -Wall -Wextra -Werror -o

SRCS=pipex.c\
	pipex_util.c\
	child_proc.c\
	parent_proc.c

SRCS_BONUS=pipex_bonus.c\
			pipex_util_bonus.c\
			child_proc_bonus.c\
			parent_proc_bonus.c

SRCS_OBJ=$(SRCS:.c=.o)
BONUS_OBJ=$(SRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES=$(BONUS_OBJ)
else
	OBJ_FILES=$(SRCS_OBJ)
endif


all: $(NAME)

# %.o:%.c
# 	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(SRCS)
	@$(MAKE) -C libft all
	$(CFLAGS) $(NAME) $(SRCS) -L ./libft -lft
	touch mandatory
	rm -f bonus

bonus: $(SRCS_BONUS)
	@$(MAKE) -C libft all
	$(CFLAGS) $(NAME) $(SRCS_BONUS) -L ./libft -lft
	touch bonus
	rm -f mandatory

clean:
	rm -f mandatory
	rm -f bonus
	@$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re