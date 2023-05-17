/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int a = my_strlen(src);
    int b = my_strlen(dest);
    int c = 0;

    while (c != a) {
        dest[b + c] = src[c];
        c = c + 1;
    }
    return dest;
}
