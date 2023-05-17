/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** header file path
*/

#ifndef PATH_H_
    #define PATH_H_

typedef struct path_s {
        char *name;
        struct path *next;
    } path_t;

#endif /* !PATH_H_ */
