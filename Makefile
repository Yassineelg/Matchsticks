##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	main_3.c	\
		main_2.c	\
		main.c

NAME	=	matchstick

all:	$(NAME)

$(NAME):
	make re -C lib/my/
	gcc $(SRC) -L. -lmy -o $(NAME)

clean:
	rm -rf *~ \#*\# .\#*

fclean:
	rm -f $(NAME)

re:	fclean all clean