#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Custom printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args_list);
			precision = get_precision(format, &i, args_list);
			size = get_size(format, &i);
			++i;
			printed_chars += handle_print(format, &i, args_list, buffer,
				flags, width, precision, size);

			if (printed_chars == -1)
				return (-1);
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(args_list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters.
 * @buffer_index: Index at which to add the next character, represents the length.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}

