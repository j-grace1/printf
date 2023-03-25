#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format.
 * @format: format string.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
    {
        return 0;
    }

    int count = 0;

    va_list arg;

    va_start(arg, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            if (format[i] == '\0')
            {
                return -1;
            }

            switch (format[i])
            {
                case 'c':
                    count += putchar(va_arg(arg, int));
                    break;
                case 's':
                    count += _print_str(va_arg(arg, char *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(format[i]);
                    break;
            }
        }
        else
        {
            count += putchar(format[i]);
        }
    }

    va_end(arg);

    return count;
}
