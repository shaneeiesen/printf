#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Handles writing a character to the buffer
 * @c: Character to write
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters written.
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';

		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padding;

		if (flags & F_MINUS)
			return write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - i - 1], width - 1);
		else
			return write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
				write(1, &buffer[0], 1);
	}
	return write(1, &buffer[0], 1);
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Writes a signed number to the buffer
 * @is_negative: Indicates if the number is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters written.
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padding = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';
	return write_num(ind, buffer, flags, width, precision,length, padding, extra_char);
}

/**
 * write_num - Writes a number to the buffer
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Flags specifier
 * @width: Width specifier
 * @prec: Precision specifier
 * @length: Number length
 * @padding: Padding character
 * @extra_char: Extra character
 *
 * Return: Number of characters written.
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
		int length, char padding, char extra_char)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return 0;
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	{
		buffer[ind] = padding = ' ';
	}

	if (prec > 0 && prec < length)
		padding = ' ';

	while (prec > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if (extra_char != 0)
		length++;

	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padding;
		buffer[i] = '\0';

		if (flags & F_MINUS && padding == ' ')
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1);
		}
		else if (!(flags & F_MINUS) && padding == ' ');
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length);
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			return write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start));
		}
	}

	if (extra_char)
		buffer[--ind] = extra_char;
	return write(1, &buffer[ind], length);
}

/**
 * write_unsgnd - Writes an unsigned number to the buffer
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padding = ' ';

	UNUSED(is_negative);
 	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return 0; /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padding = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padding;
		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return write(1, &buffer[ind], length) + write(1, &buffer[0], i);
		}
		else
		{
			return write(1, &buffer[0], i) + write(1, &buffer[ind], length);
		}
	}
	return write(1, &buffer[ind], length);
}

/**
 * write_pointer - Writes a memory address to the buffer
 * @buffer: Array of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padding: Char representing the padding
 * @extra_char: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padding, char extra_char, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padding;
		buffer[i] = '\0';

		if (flags & F_MINUS && padding == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';

			if (extra_char)
				buffer[--ind] = extra_char;
			return write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3);
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';

			if (extra_char)
				buffer[--ind] = extra_char;
			return write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length);
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';

			return write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2);
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';

	if (extra_char)
		buffer[--ind] = extra_char;
	return write(1, &buffer[ind], BUFF_SIZE - ind - 1);
}
