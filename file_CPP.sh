#!/bin/bash

# Vérification du nombre d'arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <dossier> <nombre>"
    exit 1
fi

dossier=$1
nombre=$2

format_numero(){
    numero=$1
    if [ $numero -lt 10 ]; then
        echo "0$numero"
    else
        echo "$numero"
    fi
}

for ((i = 0; i <= nombre; i++)); do
    numero_format=$(format_numero $i)
    ex_dossier="ex$numero_format"
    
    if [ ! -d "$dossier/$ex_dossier" ]; then
        mkdir -p "$dossier/$ex_dossier/src" "$dossier/$ex_dossier/inc"
        
        cat <<EOF > "$dossier/$ex_dossier/Makefile"
NAME = $ex_dossier
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -I./inc/
DFLAGS = -MMD -MP 

DSRC = ./src/
FSRC =

DOBJ = ./obj/
FOBJ = \$(FSRC:.cpp=.o)
DDEP = \$(DOBJ)
FDEP = \$(FSRC:.cpp=.d)

all: \$(NAME)

-include \$(addprefix \$(DDEP), \$(FDEP))

\$(NAME): \$(addprefix \$(DOBJ), \$(FOBJ))
	\$(CC) \$(CFLAGS) \$^ -o \$@

\$(DOBJ):
	mkdir -p \$(DOBJ)

\$(DOBJ)%.o: \$(DSRC)%.cpp | \$(DOBJ)
	\$(CC) \$(CFLAGS) \$(DFLAGS) -c \$< -o \$@

clean:
	rm -rf \$(DOBJ)

fclean: clean
	rm -f \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOF

        echo "Dossier $ex_dossier créé."
    else
        echo "Le dossier $ex_dossier existe déjà."
    fi
done

echo "Terminé."
