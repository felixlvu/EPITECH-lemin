/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strcmp
*/

int strln(char const *str)
{
    int compteur = 0;
    while (str[compteur] != '\0') {
        compteur++;;
    }
    return (compteur);
}

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    if (strln(str1) != strln(str2))
        return 0;
    while (str1[i] == str2[i] && str1[i] != '\0')
        i++;
    if (i == strln(str1))
        return 1;
    else
        return 0;
}
