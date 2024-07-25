NAME = ex00
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -I./inc/
DFLAGS = -MMD -MP 

DSRC = ./src/
FSRC = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp

DOBJ = ./obj/
FOBJ = $(FSRC:.cpp=.o)
DDEP = $(DOBJ)
FDEP = $(FSRC:.cpp=.d)

all: $(NAME)

-include $(addprefix $(DDEP), $(FDEP))

$(NAME): $(addprefix $(DOBJ), $(FOBJ))
	$(CC) $(CFLAGS) $^ -o $@

$(DOBJ):
	mkdir -p $(DOBJ)

$(DOBJ)%.o: $(DSRC)%.cpp | $(DOBJ)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean:
	rm -rf $(DOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
