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
    int count = 0;
    va_list args;
    int i, j, len;
    char *str_arg, buf[1024];
    int int_arg;

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;

            switch (format[i])
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    if (str_arg)
                    {
                        len = strlen(str_arg);
                        fwrite(str_arg, sizeof(char), len, stdout);
                        count += len;
                    }
                    break;
                case 'd':
                case 'i':
                    int_arg = va_arg(args, int);
                    len = sprintf(buf, "%d", int_arg);
                    fwrite(buf, sizeof(char), len, stdout);
                    count += len;
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
            }
        }
        else
        {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);

    return count;
}
