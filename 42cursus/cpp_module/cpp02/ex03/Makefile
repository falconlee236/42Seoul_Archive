CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = module02_ex03
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	$(CPPC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean