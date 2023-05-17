/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** parceur
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"
#include "lem_in_struct.h"
#include "my.h"

void init_struct(lem_in_t *lem_in)
{
    lem_in->rooms = malloc(sizeof(rooms_t));
    lem_in->rooms->next = NULL;
    lem_in->rooms->prev = NULL;
    lem_in->rooms->head = lem_in->rooms;
    lem_in->tunels = malloc(sizeof(tunels_t));
    lem_in->tunels->next = NULL;
    lem_in->tunels->prev = NULL;
    lem_in->tunels->head = lem_in->tunels;
}

char *next_index(char *type, char *line, lem_in_t *lem_in)
{
    if (my_strncmp(line, "##start", 7) == 1) {
        type = strchange(type, "start");
        lem_in->continu = 1;
    }
    if (my_strncmp(line, "##end", 5) == 1) {
        type = strchange(type, "end");
        lem_in->continu = 1;
    }
    return type;
}

void parser_while(lem_in_t *lem_in, char* line, size_t len, char *type)
{
    while (getline(&line, &len, stdin) != -1) {
        if (line[0] == '\n' || line[0] == '\0')
            continue;
        if (line[0] == '#' && line[1] != '#')
            continue;
        print_ant(line, type, lem_in);
        type = next_index(type, line, lem_in);
        print_start(type, line, lem_in);
        print_end(type, line, lem_in);
        if (lem_in->continu == 1) {
            lem_in->continu = 0;
            continue;
        }
        print_room(type, line, lem_in);
    }
}

void parser(lem_in_t *lem_in)
{
    size_t len = 0;
    char* line = NULL;
    char *type = NULL;
    lem_in->continu = 0;

    lem_in->init_room = 1;
    lem_in->init_tunel = 1;

    type = malloc(sizeof(char) * 4);
    type = my_strcpy(type, "ant");
    init_struct(lem_in);
    parser_while(lem_in, line, len, type);
}
