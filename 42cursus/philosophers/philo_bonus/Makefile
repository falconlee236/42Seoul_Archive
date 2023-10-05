NAME=philo_bonus
CFLAGS=cc -Wall -Wextra -Werror -o

SRCS=philo_bonus.c\
		run_philo_bonus.c\
		philo_util_bonus.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CFLAGS) $(NAME) $(SRCS)
	touch bonus

clean:
	rm -f bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re