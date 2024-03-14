CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = module01_ex00
SRCS = main.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPC) $(CPPFLAGS) $< -o $@

%.o: %.cpp
	$(CPPC) $(CPPFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean