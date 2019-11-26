##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	boostrap.c	\
		my_strlen.c	\

NAME	=	my_popup

all	:
	gcc -o $(NAME) $(SRC) -lncurses

clean	:

fclean	: clean
	rm -f $(NAME)

re	: fclean all
