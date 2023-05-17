/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-lemin-louis.huguet
** File description:
** algo
*/

#include "lem_in_struct.h"
#include "lem_in.h"
#include "my.h"
#include "path.h"
#include <stdbool.h>

int cmp_tunels(lem_in_t *lem_in, char* room, char** neighbours, int count)
{
    if (my_strcmp(lem_in->tunels->f, room) == 1) {
        neighbours[count] = malloc(sizeof
        (char) * (my_strlen(lem_in->tunels->s) + 1));
        my_strcpy(neighbours[count], lem_in->tunels->s);
        count++;
    }
    if (my_strcmp(lem_in->tunels->s, room) == 1) {
        neighbours[count] = malloc
        (sizeof(char) * (my_strlen(lem_in->tunels->f) + 1));
        my_strcpy(neighbours[count], lem_in->tunels->f);
        count++;
    }
    return count;
}

char** get_neighbours(lem_in_t *lem_in, char* room)
{
    int count = 0;
    tunels_t *head = lem_in->tunels->head;
    lem_in->tunels = lem_in->tunels->head;
    char** neighbours = malloc(sizeof(char*) * 100);
    lem_in->tunels = head;
    while (lem_in->tunels != NULL) {
        count = cmp_tunels(lem_in, room, neighbours, count);
        lem_in->tunels = lem_in->tunels->next;
    }
    lem_in->tunels = head;
    neighbours[count] = NULL;
    return neighbours;
}

bool is_visited(char *room_name, char **visited)
{
    for (int i = 0; visited[i] != NULL; i++) {
        if (my_strcmp(visited[i], room_name) == 1) {
            return true;
        }
    }
    return false;
}

void bfs(lem_in_t *lem_in, char *start, char *end, int path_length)
{
    if (my_strcmp(start, end) == 1 && lem_in->print_path == 0) {
        move_ants(lem_in->ant, lem_in->path, path_length);
        lem_in->print_path = 1;
        return;
    }
    lem_in->visited[lem_in->visited_count++] = start;
    char **neighbours = get_neighbours(lem_in, start);
    for (int i = 0; neighbours[i] != NULL; i++) {
        if (!is_visited(neighbours[i], lem_in->visited)) {
            lem_in->path[path_length] = neighbours[i];
            bfs(lem_in, neighbours[i], end, path_length + 1);
        }
        free(neighbours[i]);
    }
    free(neighbours);
    return;
}

void find_path(lem_in_t *lem_in)
{
    lem_in->visited_count = 0;
    lem_in->print_path = 0;
    lem_in->path = malloc(sizeof(char*) * 100);
    for (int i = 0; i < 100; i++)
        lem_in->path[i] = 0;
    lem_in->visited = malloc(sizeof(char*) * 100);
    for (int i = 0; i < 100; i++)
        lem_in->visited[i] = 0;
    lem_in->path[0] = lem_in->name_start;
    bfs(lem_in, lem_in->name_start, lem_in->name_end, 1);
}
