NAME=philo
CFLAGS=cc -Wall -Wextra -Werror -o

SRCS=philo.c\
		run_philo.c\
		philo_util.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CFLAGS) $(NAME) $(SRCS)
	touch mandatory

clean:
	rm -f mandatory

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re