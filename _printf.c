#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - the printf function
 * @format: the format
 * Return: the printed chars
 */
int _printf(const char *format, ...)
{
	int i, count = 0, count_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			count_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			count = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (count == -1)
				return (-1);
			count_chars += count;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (count_chars);
}

/**
 * print_buffer - prints the contents of the buffer
 * @buffer: array of characters
 * @buff_ind: index to add next char that represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}