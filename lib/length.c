/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-BSQ-antonin.campi
** File description:
** length
*/
int my_is_space(char caractere);

int compteur_mots(char const *str)
{
    int i = 0;
    int compteur = 0;

    while (str[i] != '\0') {
        if (my_is_space(str[i]) == 1) {
            i++;
            continue;
        }
        compteur++;
        while (my_is_space(str[i]) != 1 && str[i] != '\0') {
            i++;
        }
    }
    return compteur;
}

int longueur_mot(const char *str, int n)
{
    int compteur = 0;

    while (my_is_space(str[n]) != 1 && str[n] != '\0') {
        compteur++;
        n++;
    }
    return compteur;
}
