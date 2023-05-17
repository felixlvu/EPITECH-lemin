/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MY_H
    #define MY_H
    int my_printf(const char *restrict format, ...);
    int my_putstr(char const *str);
    void my_putchar(char c);
    int my_put_nbr(int b);
    char **str_to_word_array (char *str, char separator);
    char *my_strcpy(char *dest, char const *src);
    char **array_cpy(char **dest, char **src);
    char **array_cpy_noalloc(char **dest, char **src);
    int my_strlen(char const *str);
    int my_strncmp(char *str1, char *str2, int n);
    int my_atoi(char *str);
    int my_strcmp(const char *str1, const char *str2);
    char *my_strncpy(char *dest, char const *src, int n );
    char *strchange(char *dest, char *src);
    int search_char_str(char *str, char c);

#endif
