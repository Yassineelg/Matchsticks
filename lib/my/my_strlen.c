/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displays all caracteres one-by-one.
*/

int my_strlen(char const *str)
{
    int lockers = 0;

    while (str[lockers] != '\0') {
        lockers++;
    }
    return (lockers);
}
