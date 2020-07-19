/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** recoded function
*/

#include "../../Include/my.h"

void convert_dec_oct(unsigned int nb)
{
    char octal_nb[12];
    int i;

    if (nb == 0) {
        my_printf("0");
    }
    for (i = 0; nb > 0; i++) {
        octal_nb[i] = (nb % 8) + '0';
        nb /= 8;
    }
    octal_nb[i] = '\0';
    my_putstr((my_revstr(octal_nb)));
}

void get_modulo_o(va_list *list, char *str, int *i)
{
    unsigned int nb = va_arg(*list, unsigned int);

    convert_dec_oct(nb);
}

void get_modulo_s(va_list *list, char *str, int *i)
{
    char *src = va_arg(*list, char *);

    my_putstr(src);
}

void get_modulo_c(va_list *list, char *str, int *i)
{
    unsigned char c = va_arg(*list, unsigned int);

    if (c >= 0 && c >= 32 && c < 127)
        my_putchar(c);
    else if (c < 0) {
        my_putchar('\\');
        my_putchar('-');
        convert_dec_octs(-c);
    }
    else {
        my_putchar('\\');
        convert_dec_octs(c);
    }
}

void get_modulo_d(va_list * list, char *str, int *i)
{
    int nbr = va_arg(*list, int);

    my_put_nbr(nbr);
}