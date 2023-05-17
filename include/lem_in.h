/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** lem_in
*/

#include "lem_in_struct.h"
#include <stdlib.h>
#include <stdio.h>


#ifndef LEM_IN_H_
    #define LEM_IN_H_
    void parser(lem_in_t *lem_in);
    void print_ant(char *line, char *type, lem_in_t *lem_in);
    void print_after_name(int i, char *line);
    void print_start(char *type, char *line, lem_in_t *lem_in);
    void print_end(char *type, char *line, lem_in_t *lem_in);
    void print_room(char *type, char *line, lem_in_t *lem_in);
    void fill_wagon(lem_in_t *lem_in, char *line);
    void fill_tunel(lem_in_t *lem_in, char *line);
    void add_room(lem_in_t *lem_in);
    void add_tunel(lem_in_t *lem_in);
    void tunel(lem_in_t *lem_in, char *line);
    void room(lem_in_t *lem_in, char *line);
    void find_path(lem_in_t *lemin);
    int move_ants(int ant_nb, char **path, int path_length);

#endif /* !LEM_IN_H_ */
