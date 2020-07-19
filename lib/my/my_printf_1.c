/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** recoded function
*/

#include "../../Include/my.h"

int searcher_flag(char *flags, char c)
{
    int i;

    for (i = 0; flags[i] != '\0'; i++) {
        if (flags[i] == c)
            return (i);
    }
    return (-1);
}

void use_flag(va_list *list, char *str, int *i)
{
    void (*tabfunction[12]) (va_list *list, char *str, int *i) = {get_modulo_d,
    get_modulo_d, get_modulo_o, get_modulo_x, get_modulo_gx, get_modulo_u,
    get_modulo_c, get_modulo_s, get_modulo_gs, get_modulo_p, get_modulo_b,
    get_modulo_modulo};
    char flags[13] = {'d', 'i', 'o', 'x', 'X', 'u', 'c',
    's', 'S', 'p', 'b', '%', '\0'};
    int flag_dec = -1;
    int a = 1;
    int b;

    flag_dec = searcher_flag(flags, str[*i]);
    if (flag_dec != -1)
        (tabfunction[flag_dec]) (list, str, i);
    else {
        my_putchar('%');
        my_putchar(str[*i]);
    }
}

void cutted_part(va_list *list, char *str, int *i)
{
    int nb_modulo = 0;

    if (*i != 0 && str[*i - 1] == '%' && str[*i] != '%') {
        for (int a = *i - 1; str[a] == '%'; a--) {
            nb_modulo++;
        }
        if ((nb_modulo % 2) != 0) {
            nb_modulo /= 2;
            for (; nb_modulo > 0    ; nb_modulo--)
                my_putchar('%');
            use_flag(list, str, i);
        } else {
            nb_modulo /= 2;
            for (; nb_modulo > 0; nb_modulo--)
                my_putchar('%');
            my_putchar(str[*i]);
        }
    }
    else if (str[*i] != '%')
        my_putchar(str[*i]);
}

void my_printf(char *str, ...)
{
    int i;
    va_list list;

    va_start(list, str);
    for (i = 0; str[i] != '\0'; i++) {
        cutted_part(&list, str, &i);
    }
    va_end(list);
}