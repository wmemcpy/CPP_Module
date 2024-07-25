NAME := form
CC := c++
CFLAGS := -Wall -Wextra -Werror -g -std=c++98 -I./inc/
DFLAGS := -MMD -MP 

DSRC := ./src/
DOBJ := ./obj/
DDEP := ./dep/

FSRC := main.cpp Bureaucrat.cpp Form.cpp
FOBJ := $(FSRC:.cpp=.o)
FDEP := $(FSRC:.cpp=.d)

all: $(NAME)

-include $(addprefix $(DDEP), $(FDEP))

$(NAME): $(addprefix $(DOBJ), $(FOBJ))
	$(CC) $(CFLAGS) $^ -o $@

$(DOBJ) $(DDEP):
	mkdir -p $@

$(DOBJ)%.o: $(DSRC)%.cpp | $(DOBJ) $(DDEP)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -MF $(DDEP)$*.d

clean:
	rm -rf $(DOBJ) $(DDEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
