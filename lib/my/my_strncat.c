/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates two strings
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int comp = 0;

    while (dest[comp] != '\0')
        comp++;
    while (src[i] != '\0' && i < nb) {
        dest[comp + i] = src[i];
        i++;
    }
    dest[comp + i] = '\0';
    return (dest);
}
