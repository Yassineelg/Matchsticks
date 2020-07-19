/*
** EPITECH PROJECT, 2019
** my_printf3.c
** File description:
** third part of my_printf
*/

#include "../../Include/my.h"

void get_modulo_modulo(va_list *list, char *str, int *i)
{
    if (str[*i - 1] == '%' && str[*i] == '%')
        my_putchar('%');
}

void get_modulo_b(va_list *list, char *str, int *i)
{
    unsigned int nb = va_arg(*list, unsigned int);
    int index;
    char binary_nb[32];

    if (nb == 0)
        my_printf("0");
    for (index = 0; nb > 0; index++) {
        binary_nb[index] = (nb % 2) + '0';
        nb = nb / 2;
    }
    binary_nb[index] = '\0';
    my_putstr((my_revstr(binary_nb)));
}

void get_modulo_p(va_list *list, char *str, int *i)
{
    unsigned int nb = va_arg(*list, unsigned int);

    my_putstr("0x");
    convert_dec_hex(nb);
}

void get_modulo_gs(va_list *list, char *str, int *i)
{
    char *src = va_arg(*list, char *);

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] >= 32 && src[i] < 127)
            my_putchar(src[i]);
        else if (src[i] < 0) {
            my_putchar('\\');
            my_putchar('-');
            convert_dec_octs(src[i]);
        }
        else {
            my_putchar('\\');
            convert_dec_octs(src[i]);
        }
    }
}

void my_put_unsignedint(unsigned int nb)
{
    if (nb <= 9 && nb >= 0) {
        my_putchar(nb + '0');
    } else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}