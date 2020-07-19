/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int compt = 0;

    while (dest[compt] != '\0')
        compt++;
    while (src[i] != '\0') {
        dest[compt + i] = src[i];
        i++;
    }
    dest[compt + i] = '\0';
    return (dest);
}
