/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** Reverse a string.
*/

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
