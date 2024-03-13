CPPC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = megaphone
SRCS = megaphone.cpp
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