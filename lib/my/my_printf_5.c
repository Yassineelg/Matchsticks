/*
** EPITECH PROJECT, 2019
** my_printf_5.c
** File description:
** 5th part of my_printf
*/

#include "../../Include/my.h"

void convert_dec_octs(unsigned int nb)
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
    if (i == 1) {
        octal_nb[i] = '0';
        octal_nb[i + 1] = '0';
        i += 2;
    } else if (i == 2) {
        octal_nb[i] = '0';
        i++;
    }
    octal_nb[i] = '\0';
    my_putstr((my_revstr(octal_nb)));
}