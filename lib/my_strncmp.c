/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strncmp
*/

int my_strln(char const *str)
{
    int compteur = 0;
    while (str[compteur] != '\0') {
        compteur++;;
    }
    return (compteur);
}

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    while (str1[i] == str2[i] && str2[i] != '\0' && i != n)
        i++;
    if (i == my_strln(str2))
        return 1;
    else
        return 0;
}
