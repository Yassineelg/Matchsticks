/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes.
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_printf(char *str, ...);
char *my_rev_putnbr(int nb);
int my_getnbr(char *str);

typedef struct my_struct_s {
    char **map;
    int error_matches;
    int error_line;
    int pips_on_line;
    int matches;
    int colones;
    int player;
    int lines;
    int a;
    int b;
    int x;
    int y;
} my_t;

int ia(my_t *mat);
int ask_line(my_t *mat, int line);
int ask_matches(my_t *mat, int matches, int line);
void delete_matches(my_t *mat, int matches, int line);


#endif