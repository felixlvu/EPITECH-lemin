/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** strchange
*/

#include <stdlib.h>
#include "my.h"

char *strchange(char *dest, char *src)
{
    free(dest);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return dest;
}
