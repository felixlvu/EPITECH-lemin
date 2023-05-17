/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

int check_type(const char *restrict format, int i, va_list va_s)
{
    if (format[i] == 's')
        my_putstr(va_arg(va_s, char *));
    if (format[i] == 'd' || format[i] == 'i')
        my_put_nbr(va_arg(va_s, int));
    if (format[i] == 'c')
        my_putchar(va_arg(va_s, int));
    if (format[i] == '%')
        my_putchar('%');
    return i;
}

int my_printf(const char *restrict format, ...)
{
    va_list va_s;

    va_start(va_s, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i = check_type(format, i + 1, va_s);
        else
            my_putchar(format[i]);
    }
    return 0;
}
