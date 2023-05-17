/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** search_char_str
*/

int search_char_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
