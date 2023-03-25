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
                    {
                        char *str = va_arg(arg, char *);
                        if (str == NULL)
                        {
                            count += _print_str("(null)");
                        }
                        else
                        {
                            count += _print_str(str);
                        }
                    }
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
