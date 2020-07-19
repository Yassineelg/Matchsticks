/*
** EPITECH PROJECT, 2020
** main_3.c
** File description:
** main_3
*/

#include "my.h"

int ia(my_t *mat)
{
    int matches;
    int line = random() % (mat->lines - 1);

    for (int i = 0; i < mat->lines; i++) my_printf("%s\n", mat->map[i]);
    my_printf("\nAI's turn...\n");
    mat->player = 2;
    mat->pips_on_line = 0;
    while (mat->pips_on_line == 0) {
        line = random() % (mat->lines - 1);
        for (int x = 0; mat->map[line][x] != '\0'; x++)
            if (mat->map[line][x] == '|') mat->pips_on_line++;
    }
    if (mat->pips_on_line > mat->b)
        matches = mat->b;
    else if (mat->pips_on_line <= mat->b && mat->pips_on_line != 1)
        matches = mat->pips_on_line - 1;
    else
        matches = mat->pips_on_line;
    delete_matches(mat, matches, line);
}