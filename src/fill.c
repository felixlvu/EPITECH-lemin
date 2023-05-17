/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** fill
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"
#include "lem_in_struct.h"
#include "my.h"

void fill_wagon(lem_in_t *lem_in, char *line)
{
    int i = 0;

    for (; line[i] != ' '; i++);
    lem_in->rooms->name_room = malloc(sizeof(char) * (i + 1));
    lem_in->rooms->name_room = my_strncpy(lem_in->rooms->name_room, line, i);
    my_printf("%s ", lem_in->rooms->name_room);
    i++;
    print_after_name(i, line);
}

void fill_tunel(lem_in_t *lem_in, char *line)
{
    int i = 0;
    int j = 0;

    for (; line[i] != '-'; i++);
    lem_in->tunels->f = malloc(sizeof(char) * (i + 1));
    lem_in->tunels->f = my_strncpy(lem_in->tunels->f, line, i);
    i++;
    for (j = i; line[j] != '\n' && line[j] != '#' &&
    line[j] != ' ' && line[j] != '\0'; j++);
    lem_in->tunels->s = malloc(sizeof(char) * (my_strlen(line) - (j - i + 1)));
    for (int k = 0; i < j; i++, k++)
        lem_in->tunels->s[k] = line[i];
    my_printf("%s-%s\n", lem_in->tunels->f, lem_in->tunels->s);
}

void add_room(lem_in_t *lem_in)
{
    lem_in->rooms->next = malloc(sizeof(rooms_t));
    lem_in->rooms->next->prev = lem_in->rooms;
    lem_in->rooms->next->next = NULL;
    lem_in->rooms->next->head = lem_in->rooms->head;
    lem_in->rooms = lem_in->rooms->next;
}

void add_tunel(lem_in_t *lem_in)
{
    lem_in->tunels->next = malloc(sizeof(tunels_t));
    lem_in->tunels->next->prev = lem_in->tunels;
    lem_in->tunels->next->next = NULL;
    lem_in->tunels->next->head = lem_in->tunels->head;
    lem_in->tunels = lem_in->tunels->next;
}
