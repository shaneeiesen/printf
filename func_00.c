#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char sign_char = 0, padding_char = ' ';
	int buffer_index = BUFF_SIZE - 2, output_length = 2;
	unsigned long address_value;
	char hex_dIgits[] = "0123456789abcdef";
	void *address = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	address_value = (unsigned long)address;

	while (address_value > 0)
	{
		buffer[buffer_index--] = hex_digits[address_value % 16];
		address_value /= 16;
		output_length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (flags & F_PLUS)
		sign_char = '+', output_length++;
	else if (flags & F_SPACE)
		sign_char = ' ', output_length++;

	buffer_index++;
	return (write_pointer(buffer, buffer_index, output_length,
				width, flags, padding_char, sign_char, 1));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_non_printable(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int str_index = 0, buffer_offset = 0;
	char *input_str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (input_str == NULL)
		return (write(1, "(null)", 6));

	while (input_str[str_index] != '\0')
	{
		if (is_printable(input_str[str_index]))
			buffer[str_index + buffer_offset] = input_str[str_index];
		else
			buffer_offset += append_hexa_code(input_str[str_index],\
					buffer, str_index + buffer_offset);
		str_index++;
	}

	buffer[str_index + buffer_offset] = '\0';
	return (write(1, buffer, str_index + buffer_offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int str_len, char_count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}

	for (str_len = 0; str[str_len]; str_len++)
		;
	for (str_len = str_len - 1; str_len >= 0; str_len--)
	{
		char current_char = str[str_len];

		write(1, &current_char, 1);
		char_count++;
	}
	return (char_count);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char transformed_char;
	char *input_str;
	unsigned int i, j;
	int output_count = 0;
	char normal_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
		abcdefghijklmnopqrstuvwxyz";
	char rot13_alphabet[] = "NOPQRSTUVWXYZABCDEFGHIJKLM\
		nopqrstuvwxyzabcdefghijklm";

	input_str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (input_str == NULL)
		input_str = "(AHYY)";
	for (i = 0; input_str[i]; i++)
	{
		for (j = 0; normal_alphabet[j]; j++)
		{
			if (normal_alphabet[j] == input_str[i])
			{
				transformed_char = rot13_alphabet[j];
				write(1, &transformed_char, 1);
				output_count++;
				break;
			}
		}
		if (!normal_alphabet[j])
		{
			transformed_char = input_str[i];
			write(1, &transformed_char, 1);
			output_count++;
		}
	}
	return (output_count);
}
