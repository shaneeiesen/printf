#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - the printf function
 * @format: format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFF_SIZE];
	int flags, width, precision, size, buff_ind = 0;
	int x, printed = 0, printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &x);
			width = get_width(format, &x, list);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: array of chars
 * @buff_ind: Index at which to add next char, represents the lengt
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
