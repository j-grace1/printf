#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;

            switch (format[i]) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }

                case 's': {
                    char *s = va_arg(args, char *);
                    if (s == NULL) {
                        s = "";
                    }
                    printf("%s", s);
                    count += strlen(s);
                    break;
                }

                case '%': {
                    putchar('%');
                    count++;
                    break;
                }

                default: {
                    printf("Error: invalid format specifier %%%c\n", format[i]);
                    return -1;
                }
            }
        } else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}
