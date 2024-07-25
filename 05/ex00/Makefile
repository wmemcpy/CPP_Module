NAME := bureaucrat
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -g -std=c++98 -ansi -pedantic -I./inc/
DFLAGS := -MMD -MP 

DSRC := ./src/
DOBJ := ./obj/
DDEP := ./dep/

FSRC := main.cpp Bureaucrat.cpp
FOBJ := $(FSRC:.cpp=.o)
FDEP := $(FSRC:.cpp=.d)

all: $(NAME)

-include $(addprefix $(DDEP), $(FDEP))

$(NAME): $(addprefix $(DOBJ), $(FOBJ))
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DOBJ) $(DDEP):
	mkdir -p $@

$(DOBJ)%.o: $(DSRC)%.cpp | $(DOBJ) $(DDEP)
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@ -MF $(DDEP)$*.d

clean:
	rm -rf $(DOBJ) $(DDEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

scan-build: clean
	scan-build make | grep '^scan-build:'

.PHONY: all clean fclean re scan-build
