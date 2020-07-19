/*
** EPITECH PROJECT, 2019
** my_printf4.c
** File description:
** 4th part of my_printf
*/

#include "../../Include/my.h"

void get_modulo_u(va_list *list, char *str, int *i)
{
    unsigned int nb = va_arg(*list, unsigned int);

    my_put_unsignedint(nb);
}

void convert_dec_hex(unsigned int nb)
{
    unsigned int i = 0;

    if (nb >= 16) {
        i = nb % 16;
        nb = nb / 16;
        convert_dec_hex(nb);
    }
    else if (nb > 0)
        i = nb % 16;
    if (i > 9)
        my_putchar(i + 'a' - 10);
    else
        my_putchar(i + '0');
}

void convert_dec_ghex(unsigned int nb)
{
    unsigned int i = 0;

    if (nb >= 16) {
        i = nb % 16;
        nb = nb / 16;
        convert_dec_ghex(nb);
    }
    else if (nb > 0)
        i = nb % 16;
    if (i > 9)
        my_putchar(i + 'A' - 10);
    else
        my_putchar(i + '0');
}

void get_modulo_x(va_list *list, char *str, int *i)
{
    unsigned int nb = va_arg(*list, unsigned int);

    convert_dec_hex(nb);
}

void get_modulo_gx(va_list *list, char *str, int *i)
{
    unsigned int nb = va_arg(*list, unsigned int);

    convert_dec_ghex(nb);
}