#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;

                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    count += putchar('%');
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}


