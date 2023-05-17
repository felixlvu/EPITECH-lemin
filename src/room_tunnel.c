/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** room_tunnel
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"
#include "lem_in_struct.h"
#include "my.h"

void room(lem_in_t *lem_in, char *line)
{
    if (lem_in->init_room == 0) {
        add_room(lem_in);
        fill_wagon(lem_in, line);
    } else {
        fill_wagon(lem_in, line);
        lem_in->init_room = 0;
    }
}

void tunel(lem_in_t *lem_in, char *line)
{
    if (lem_in->init_tunel == 0) {
        add_tunel(lem_in);
        fill_tunel(lem_in, line);
    } else {
        my_printf("#tunnels\n");
        fill_tunel(lem_in, line);
        lem_in->init_tunel = 0;
    }
}
