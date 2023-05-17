/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** print_parser
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "lem_in.h"
#include "lem_in_struct.h"

void print_ant(char *line, char *type, lem_in_t *lem_in)
{
    if (my_strcmp(type, "ant") == 1) {
        lem_in->ant = my_atoi(line);
        my_printf("#number_of_ants\n");
        my_printf("%d\n", lem_in->ant);
        type = strchange(type, "next");
        my_printf("#rooms\n");
        lem_in->continu = 1;
    }
}

void print_after_name(int i, char *line)
{
    int count_space = 0;

    for (; line[i] != '\n' && line[i] != '#' && line[i] != '\0'; i++) {
        if (line[i] == ' ')
            count_space++;
        if (count_space == 2)
            break;
        my_printf("%c", line[i]);
    }
    my_printf("\n");
}

void print_start(char *type, char *line, lem_in_t *lem_in)
{
    size_t len = 0;

    if (my_strcmp(type, "start") == 1) {
        int i = 0;
        getline(&line, &len, stdin);
        my_printf("##start\n");
        for (; line[i] != ' '; i++);
        lem_in->name_start = malloc(sizeof(char) * i + 1);
        lem_in->name_start = my_strncpy(lem_in->name_start, line, i);
        my_printf("%s ", lem_in->name_start);
        i++;
        print_after_name(i, line);
        type = strchange(type, "next");
        lem_in->continu = 1;
    }
}

void print_end(char *type, char *line, lem_in_t *lem_in)
{
    size_t len = 0;

    if (my_strcmp(type, "end") == 1) {
        int i = 0;
        getline(&line, &len, stdin);
        my_printf("##end\n");
        for (; line[i] != ' '; i++);
        lem_in->name_end = malloc(sizeof(char) * i + 1);
        lem_in->name_end = my_strncpy(lem_in->name_end, line, i);
        my_printf("%s ", lem_in->name_end);
        i++;
        print_after_name(i, line);
        type = strchange(type, "next");
        lem_in->continu = 1;
    }
}

void print_room(char *type, char *line, lem_in_t *lem_in)
{
    if (my_strcmp(type, "next")) {
        if (search_char_str(line, '-') == 0)
            room(lem_in, line);
        else
            tunel(lem_in, line);
    }
}
