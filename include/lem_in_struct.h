/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** lem_in_struct
*/

#ifndef LEM_IN_STRUCT_H_
    #define LEM_IN_STRUCT_H_
    typedef struct lem_in {
        struct rooms *rooms;
        struct tunels *tunels;
        int continu;
        int print_path;
        int ant;
        int init_room;
        int init_tunel;
        char **path;
        char **visited;
        int visited_count;
        char *name_start;
        char *name_end;
    } lem_in_t;

    typedef struct rooms {
        char *name_room;
        struct rooms *next;
        struct rooms *prev;
        struct rooms *head;
    } rooms_t;

    typedef struct tunels {
        char *f;
        char *s;
        struct tunels *next;
        struct tunels *prev;
        struct tunels *head;
    } tunels_t;

    typedef struct move_ant {
        int *rooms;
        int *ant_pos;
        int end_room;
    } move_ant_t;

#endif /* !LEM_IN_STRUCT_H_ */
