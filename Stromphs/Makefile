##
## EPITECH PROJECT, 2021
## makefile
## File description:
## file which compiles libmy
##

SRC	=	$(shell echo sources/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_babysleep

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-audio	\
	-lcsfml-system -lcsfml-window -lm -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
