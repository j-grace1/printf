#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _strlen(char *s)
{
    int len = 0;
    while (*s++)
        len++;
    return len;
}

void _print_number(int n)
{
    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    if (n / 10) {
        _print_number(n / 10);
    }

    _putchar((n % 10) + '0');
}

void _print_string(char *str)
{
    while (*str) {
        _putchar(*str++);
    }
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    _putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    _print_string(va_arg(args, char *));
                    count += _strlen(va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    _print_number(va_arg(args, int));
                    break;
                case 'o':
                    _print_string("0");
                    _print_number(va_arg(args, unsigned int));
                    break;
                case 'x':
                case 'X':
                    {
                        char *hex_digits = "0123456789abcdef";
                        char buf[32] = { 0 };
                        int n = va_arg(args, unsigned int);
                        int i = 30;
                        while (n) {
                            buf[i--] = hex_digits[n % 16];
                            n /= 16;
                        }
                        if (*format == 'X') {
                            for (int j = i + 1; j <= 30; j++) {
                                if (buf[j] >= 'a' && buf[j] <= 'f') {
                                    buf[j] = buf[j] - 32;
                                }
                            }
                        }
                        _print_string(buf + i + 1);
                        count += _strlen(buf + i + 1);
                    }
                    break;
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
