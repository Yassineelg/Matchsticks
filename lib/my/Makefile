##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_swap.c	\
		my_getnbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcat.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strncat.c	\
		my_strncpy.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_printf_1.c	\
		my_printf_2.c	\
		my_printf_3.c	\
		my_printf_4.c	\
		my_rev_putnbr.c	\
		my_printf_5.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../..

clean:
	rm -rf *~ \#*\# .\#* *.o

fclean:
	rm -f $(NAME)

re:	fclean all clean