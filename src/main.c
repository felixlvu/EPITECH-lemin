/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"
#include "lem_in_struct.h"

int main(void)
{
    lem_in_t *lem_in = malloc(sizeof(lem_in_t));

    parser(lem_in);
    find_path(lem_in);
    return 0;
}
