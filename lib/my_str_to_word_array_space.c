/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_str_to_word_array
*/
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);
int compteur_mots(char const *str);
int longueur_mot(const char *str, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_putstr(char const *str);
void my_putchar(char c);
void my_put_nbr(int a);
char *my_strncpy2(char *dest, char const *src, int n);


int my_is_space(char caractere)
{
    if (caractere == ' ') {
        return 1;
    } else {
        return 0;
    }
}

int debut_str(const char* str)
{
    int nb = 0;
    while (my_is_space(str[nb]) == 1) {
        nb++;
    }
    return nb;
}

char **my_str_to_word_array(char const *str)
{
    int n = 0, word = 0;
    int count = compteur_mots(str);
    char **array = malloc(sizeof(char*) * (count + 1));

    n = debut_str(str);

    while (str[n] != '\0') {
        if (my_is_space(str[n]) == 1) {
            n++;
            continue;
        }
        int length = longueur_mot(str, n);
        array[word] = malloc(sizeof(char) * (length + 1));
        my_strncpy(array[word], str + n, length);
        array[word][length] = '\0';
        word++;
        n = n + length;
    }
    array[word] = NULL;
    return array;
}
