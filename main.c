/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "my.h"

int error_handling(int ac, char **av, my_t *mat)
{
    if (ac != 3)
        return (84);
    for (int i = 0; av[1][i]; i++) {
        if (av[1][i] < '0' || av[1][i] > '9')
            return (84);
    }
    for (int i = 0; av[2][i]; i++)
        if (av[2][i] < '0' || av[2][i] > '9') return (84);
    mat->a = my_getnbr(av[1]);
    mat->b = my_getnbr(av[2]);
    if (mat->a <= 1 || mat->a >= 99|| mat->b <= 0) return (84);
    return (0);
}

void setup_map(my_t *mat)
{
    int start = 1;
    int end = (mat->a * 2 + 1) - 2;

    mat->lines = mat->a + 2;
    mat->colones = mat->a * 2 + 1;
    mat->map = malloc(sizeof(char *) * mat->lines + 1);
    for (int i = 0; i < mat->lines; i++)
        mat->map[i] = malloc(sizeof(char) * mat->colones + 2);
    for (int y = 0; y <= mat->lines - 1; y++)
        for (int x = 0; x < mat->colones; x++) {
            mat->map[y][x] = (y == 0 || y == mat->lines - 1 || x == 0 ||
            x == mat->colones - 1) ? '*' : ' ';
        }
    for (int y = mat->lines - 2; y > 0; y--, start++, end--)
        for (int x = start; x <= end; x++) {
            mat->map[y][x] = '|';
            mat->matches++;
        }
}

void free_function(my_t *mat)
{
    for (int i = 0; i < (mat->a + 3); i++) free(mat->map[i]);
    free(mat->map);
}

int game(my_t *mat)
{
    int matches;
    int line;

    mat->player = 1;
    for (int i = 0; i < mat->lines; i++) my_printf("%s\n", mat->map[i]);
    my_printf("\nYour turn:\n");
    while (mat->error_matches == 0 || mat->error_line == 0) {
        while (mat->error_line == 0) {
            line = ask_line(mat, line);
            if (line == -1) return (-1);
        }
        matches = ask_matches(mat, matches, line);
        if (mat->error_matches == 0) mat->error_line = 0;
        if (matches == -1) return (-1);
    }
    mat->error_matches = 0;
    mat->error_line = 0;
    delete_matches(mat, matches, line);
    return (1);
}

int main(int ac, char **av)
{
    my_t *mat = malloc(sizeof(my_t));
    int ret = 0;

    if (error_handling(ac, av, mat) == 84) return (84);
    setup_map(mat);
    while (mat->matches != 0) {
        ret = game(mat);
        if (ret == -1) return (0);
        if (mat->matches != 0) ia(mat);
    }
    for (int i = 0; i < mat->lines; i++) my_printf("%s\n", mat->map[i]);
    if (mat->player == 2) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        ret = 1;
    } else if (mat->player == 1) {
        my_printf("You lost, too bad...\n");
        ret = 2;
    }
    free_function(mat);
    return (ret);
}