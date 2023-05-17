/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** print nombres
*/

#include "my.h"

int recur(int nombr)
{
    int temp = 0;

    temp = nombr % 10;
    if (nombr <= 0) {
        return (0);
    }
    nombr = nombr / 10;
    recur(nombr);
    my_putchar(temp + 48);
    return (0);
}

int my_put_nbr(int b)
{

    if (b == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
        return (0);
    }

    if (b < 0) {
        b = -b;
        my_putchar('-');
        recur(b);
        return (0);
    }
    if (b == 0) {
        my_putchar('0');
        return (0);
    }
    recur(b);
}
