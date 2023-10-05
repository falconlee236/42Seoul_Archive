NAME=philo
CFLAGS=cc -Wall -Wextra -Werror -o

SRCS=philo.c\
		run_philo.c\
		philo_util.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CFLAGS) $(NAME) $(SRCS)
	touch mandatory
	rm -f bonus

bonus: $(SRCS_BONUS)
	$(CFLAGS) $(NAME) $(SRCS_BONUS)
	touch bonus
	rm -f mandatory

clean:
	rm -f mandatory
	rm -f bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re