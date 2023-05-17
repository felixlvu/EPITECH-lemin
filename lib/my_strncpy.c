/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** string in another
*/

int my_len(char const *str)
{
    int compteur = 0;
    while (str[compteur] != '\0') {
        compteur++;
    }
    return (compteur);
}

char *my_strncpy(char *dest, char const *src, int n )
{
    int i;

    for (i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    if (n < my_len(src)) {
        dest[i + 1] = '\0';
        return (dest);
    }
    if (n > my_len(src))
        return (dest);
}
