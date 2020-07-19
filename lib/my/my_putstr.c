/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displays all caracteres one-by-one.
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int lockers = 0;

    while (str[lockers] != '\0') {
        my_putchar(str[lockers]);
        lockers++;
    }
}