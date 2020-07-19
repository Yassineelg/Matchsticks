/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes.
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c);
void my_put_nbr(int nb);
char *my_revstr(char *str);
void my_swap(int *a, int *b);
int my_strlen(char const *str);
void my_printf(char *str, ...);
int my_getnbr(char const *str);
void my_putstr(char const *str);
void convert_dec_hex(unsigned int nb);
void convert_dec_oct(unsigned int nb);
int flag_searcher(char *flags, char c);
void convert_dec_octs(unsigned int nb);
void my_put_unsignedint(unsigned int nb);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
void no_flag(va_list *list, char *str, int *i);
void get_modulo_s(va_list *list, char *str, int *i);
void get_modulo_c(va_list *list, char *str, int *i);
void get_modulo_d(va_list *list, char *str, int *i);
void get_modulo_o(va_list *list, char *str, int *i);
void get_modulo_x(va_list *list, char *str, int *i);
void get_modulo_u(va_list *list, char *str, int *i);
void get_modulo_p(va_list *list, char *str, int *i);
void get_modulo_n(va_list *list, char *str, int *i);
void get_modulo_b(va_list *list, char *str, int *i);
void get_modulo_gs(va_list *list, char *str, int *i);
void get_modulo_gx(va_list *list, char *str, int *i);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strncat(char *dest, char const *src, int nb);
void get_modulo_modulo(va_list *list, char *str, int *i);