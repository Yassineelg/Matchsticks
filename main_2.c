/*
** EPITECH PROJECT, 2020
** main_2.c
** File description:
** main_2
*/

#include "my.h"

void delete_matches(my_t *mat, int matches, int line)
{
    int x = 1;
    int fake_matches = matches;

    mat->matches -= matches;
    for (; mat->map[line][x] != '|'; x++);
    for (; mat->map[line][x] != ' ' && mat->map[line][x] != '*'; x++);
    for (x -= 1; fake_matches; fake_matches--, x--)
        mat->map[line][x] = ' ';
    if (mat->player == 1)
        my_printf("Player removed %d match(es) from line %d\n", matches, line);
    else if (mat->player == 2)
        my_printf("AI removed %d match(es) from line %d\n", matches, line);
}

int ask_line_error(my_t *mat, char *buffer, int line)
{
    for (int i = 0; buffer[i] != '\n'; i++) {
        if (buffer[i] < '0' || buffer[i] > '9' || my_getnbr(buffer) < 0) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (0);
        }
    } if (line == 0 || line >= mat->lines - 1) {
        my_printf("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}

int ask_line(my_t *mat, int line)
{
    char *buffer = NULL;
    size_t len = 1;
    ssize_t size = 0;
    int ret_error = 1;

    my_printf("Line: ");
    while (size == 0) {
        size = getline(&buffer, &len, stdin);
        if (size == -1) return (-1);
    }
    line = my_getnbr(buffer);
    ret_error = ask_line_error(mat, buffer, line);
    if (ret_error == 0) return (0);
    mat->error_line = 1;
    return (line);
}

int ask_matches_error(my_t *mat, char *buffer, int line, int matches)
{
    for (int i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] < '0' || buffer[i] > '9' || my_getnbr(buffer) < 0) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (0);
        }
    mat->pips_on_line = 0;
    for (int x = 0; mat->map[line][x] != '\0'; x++)
        if (mat->map[line][x] == '|') mat->pips_on_line++;
    if (matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (0);
    } if (matches > mat->b) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
        mat->b);
        return (0);
    } else if (matches > mat->pips_on_line) {
        my_printf("Error: not enough matches on this line\n");
        return (0);
    }
    return (1);
}

int ask_matches(my_t *mat, int matches, int line)
{
    char *buffer = NULL;
    size_t len = 1;
    ssize_t size = 0;
    int ret_error = 1;

    my_printf("Matches: ");
    while (size == 0) {
        size = getline(&buffer, &len, stdin);
        if (size == -1) return (-1);
    }
    matches = my_getnbr(buffer);
    ret_error = ask_matches_error(mat, buffer, line, matches);
    if (ret_error == 0) return (0);
    mat->error_matches = 1;
    return (matches);
}