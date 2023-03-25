#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    for (int j = 0; s[j] != '\0'; j++) {
                        putchar(s[j]);
                        printed_chars++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    printed_chars++;
                    break;
                }
            }
        } else {
            putchar(format[i]);
            printed_chars++;
        }
    }

    va_end(args);
    return printed_chars;
}
