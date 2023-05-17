/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-lemin-louis.huguet
** File description:
** move_ants
*/

#include "lem_in_struct.h"
#include "lem_in.h"
#include "my.h"
#include "path.h"
#include <stdbool.h>

void move_ants_nxt(move_ant_t *move_ant, int ant_nb, char **path, int room_nb)
{
    for (int ant = 0; ant < ant_nb; ant++) {
        if ((move_ant->ant_pos[ant] + 1) == room_nb - 1) {
            my_printf("P%d-%s ", ant + 1,
            path[move_ant->ant_pos[ant] + 1]);
            move_ant->rooms[move_ant->ant_pos[ant] + 1]++;
            move_ant->rooms[move_ant->ant_pos[ant]]--;
            move_ant->ant_pos[ant]++;
            move_ant->end_room++;
        }
        if (move_ant->ant_pos[ant] != room_nb - 1 &&
        move_ant->rooms[move_ant->ant_pos[ant] + 1] == 0) {
            my_printf("P%d-%s ", ant + 1, path[move_ant->ant_pos[ant] + 1]);
            move_ant->rooms[move_ant->ant_pos[ant] + 1]++;
            move_ant->rooms[move_ant->ant_pos[ant]]--;
            move_ant->ant_pos[ant]++;
        }
        if (ant == ant_nb - 1) {
            my_printf("\n");
        }
    }
}

int move_ants(int ant_nb, char **path, int path_length)
{
    move_ant_t *move_ant = malloc(sizeof(move_ant_t));
    int room_nb = path_length;
    move_ant->end_room = 0;

    my_printf("#moves\n");
    move_ant->rooms = malloc(sizeof(int) * room_nb);
    for (int i = 0; i < room_nb; i++) {
        move_ant->rooms[i] = 0;
    }
    move_ant->ant_pos = malloc(sizeof(int) * ant_nb);
    for (int i = 0; i < ant_nb; i++) {
        move_ant->ant_pos[i] = 0;
    }
    while (move_ant->end_room != ant_nb) {
        move_ants_nxt(move_ant, ant_nb, path, room_nb);
    }
    return 0;
}
