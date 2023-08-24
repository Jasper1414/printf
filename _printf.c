#include "main.h"

/**
 * _printf - the printf function
 * @format: the format string
 * Return: number of printed chars
 */
int _printf(const char *format, ...)
{
	int print_chars = 0;
	va_list list_arg;

	if (format == NULL)
		return (-1);

	va_start(list_arg, format);

	while (*format) {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    print_chars++;
                    break;
                case 's':
                    printed_chars += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    print_chars++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    print_chars += 2;
            }
        } else {
            putchar(*format);
            print_chars++;
        }

        format++;
    }

    va_end(args);
    return printed_chars;
}
