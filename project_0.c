#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;

    len = _printf("Let's print a simple sentence.\n");
    _printf("Length of string: %d\n", len);
    return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _printf - produces output according to a format
 * @format: a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int i, count = 0;
    va_list args;
    char *str_arg;
    char buffer[1024];

    va_start(args, format);
    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
            case 's':
                str_arg = va_arg(args, char *);
                count += _print_str(str_arg, buffer);
                break;
            case '%':
                _putchar('%');
                count++;
                break;
            default:
                _putchar('%');
                _putchar(format[i]);
                count += 2;
                break;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }
    va_end(args);

    write(1, buffer, _strlen(buffer));
    return (count);
}

/**
 * _print_str - prints a string to a buffer
 * @str: the string to print
 * @buffer: the buffer to print to
 *
 * Return: the number of characters printed
 */
int _print_str(char *str, char *buffer)
{
    int i, len;

    len = _strlen(str);
    for (i = 0; i < len; i++)
        buffer[i] = str[i];

    return (len);
}

/**
 * _strlen - calculates the length of a string
 * @str: the string to measure
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;

    return (i);
}
