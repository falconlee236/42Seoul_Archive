NAME=PmergeMe

RED="\033[0;31m Warining: "
GREEN="\033[3;32m"
ANCI_INIT="\033[0m"

DEP_DIR=depend
OBJ_DIR=objs

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror
CXXFLAGS+=-std=c++98
# CXXFLAGS+=-g -fsanitize=address
CXXFLAGS+=-MMD -MP -MF $(DEP_DIR)/$*.d

RM=rm -rf

SRCS=$(wildcard *.cpp)
OBJS=$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPD=$(addprefix $(DEP_DIR)/, $(SRCS:.cpp=.d))

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ \
	&& echo $(GREEN)"Compiled successful!" $<$(ANCI_INIT) \
	|| echo $(RED)"Failed to compile $<"$(ANCI_INIT);

$(DEP_DIR)/%.d: %.cpp
	@mkdir -p $(DEP_DIR)

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJ_DIR) \
	&& echo $(GREEN)"Clean successful!"$(ANCI_INIT) \
	|| echo $(RED)"Clean failed!"$(ANCI_INIT);

fclean:
	@$(RM) $(OBJS) $(DEPD) $(OBJ_DIR) $(DEP_DIR) $(NAME)\
	&& echo $(GREEN)"fclean successful!"$(ANCI_INIT) \
	|| echo $(RED)"fclean failed!"$(ANCI_INIT);

re:
	@make fclean
	@make all

-include $(DEPD)

.PHONY: all clean fclean re
