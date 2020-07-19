/*
** EPITECH PROJECT, 2019
** my_rev_putnbr.c
** File description:
** int to char *
*/

#include <stdlib.h>
#include <stdio.h>

char *my_revstr(char *str)
{
    int i = 0;
    int rev = 0;
    char tempo;

    while (str[i] != '\0')
        i++;
    i--;
    while (rev < i) {
        tempo = str[i];
        str[i] = str[rev];
        str[rev] = tempo;
        i--;
        rev++;
    }
    return (str);
}

char *negativ_nbr(int nb, char *str, int i, int a)
{
    nb *= -1;
    for (int tempo = nb; tempo > 0; tempo /= 10)
        i++;
    str = malloc(sizeof(char) * i + 2);
    for (; nb > 0; a++) {
        str[a] = (nb % 10) + '0';
        nb /= 10;
    }
    str[a] = '-';
    return (my_revstr(str));
}

char *positiv_nbr(int nb, char *str, int i, int a)
{
    for (int tempo = nb; tempo > 0; tempo /= 10)
        i++;
    str = malloc(sizeof(char) * i + 1);
    str[i] = '\0';
    for (; nb > 0; a++) {
        str[a] = (nb % 10) + '0';
        nb /= 10;
    }
    return (my_revstr(str));
}

char *my_rev_putnbr(int nb)
{
    char *str;
    int i = 0;
    int a = 0;

    if (nb == 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = 0 + '0';
        str[1] = '\0';
        return (my_revstr(str));
    }
    if (nb < 0) {
        negativ_nbr(nb, str, i, a);
    } else {
        positiv_nbr(nb, str, i, a);
    }
}