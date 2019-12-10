##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	main.c	\
		fill.c	\
		my_str_to_word_array.c	\

NAME	=	my_sokoban

OBJ	=	libmy.a

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

VG	=	-g3

ERROR	=	-Wall -W -Wextra

NCURSE	=	-lncurses

all	:	$(OBJ)

$(OBJ)	:
	gcc -c lib/my/*.c
	ar rc $(OBJ) *.o
	gcc -o $(NAME) $(SRC) $(NCURSE) $(VG)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
