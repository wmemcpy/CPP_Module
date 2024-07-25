NAME = megaphone
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
