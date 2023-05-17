/*
** EPITECH PROJECT, 2023
** minishell1 [WSL : Ubuntu]
** File description:
** array_cpy
*/

#include <stdlib.h>
#include "my.h"

char **array_cpy(char **dest, char **src)
{
    int nb_c = 0;
    int i = 0;

    for (nb_c = 0; src[nb_c] != NULL; nb_c++);
    dest = malloc(sizeof(char*) * (nb_c + 1));
    for (i = 0; src[i] != NULL; i++) {
        dest[i] = malloc(my_strlen(src[i]) + 1);
        dest[i] = my_strcpy(dest[i], src[i]);
    }
    dest[i] = NULL;
    return dest;
}

char **array_cpy_noalloc(char **dest, char **src)
{
    int nb_c = 0;
    int i = 0;

    for (i = 0; src[i] != NULL; i++) {
        dest[i] = malloc(my_strlen(src[i]) + 1);
        dest[i] = my_strcpy(dest[i], src[i]);
    }
    return dest;
}
