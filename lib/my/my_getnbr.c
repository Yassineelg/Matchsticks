/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Char en int
*/

#include "../../Include/my.h"

int neg_function(char const *str, int *i, int neg)
{
    if (str[*i - 1] == '-')
        neg = -neg;
    return (neg);
}

int nb_function(char const *str, int i, int *nb)
{
    for (; str[i] >= '0' && str[i] <= '9'; i++)
        *nb = *nb * 10 + (str[i] - '0');
    return (i);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            neg = neg_function(str, &i, neg);
            i = nb_function(str, i, &nb);
        }
        else
            i++;
    }
    nb *= neg;
    return (nb);
}