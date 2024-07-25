NAME := PmergeMe
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -ggdb -std=c++98
DFLAGS := -MMD -MP 

DSRC := ./src/
DOBJ := ./obj/
DDEP := ./dep/
DINC := ./inc/

FSRC := main.cpp PmergeMe.cpp
FOBJ := $(FSRC:.cpp=.o)
FDEP := $(FSRC:.cpp=.d)

.PHONY: all clean fclean re scan-build

all: $(NAME)

-include $(addprefix $(DDEP), $(FDEP))

$(NAME): $(addprefix $(DOBJ), $(FOBJ))
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DOBJ) $(DDEP):
	mkdir -p $@

$(DOBJ)%.o: $(DSRC)%.cpp | $(DOBJ) $(DDEP)
	$(CXX) $(CXXFLAGS) -I$(DINC) $(DFLAGS) -c $< -o $@ -MF $(DDEP)$*.d

clean:
	rm -rf $(DOBJ) $(DDEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

scan-build: clean
	scan-build make | grep "^scan-build:"
