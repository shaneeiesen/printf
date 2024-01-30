#include "main.h"

/**
 * print_pointer - prints the value of a pointer variable
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size specifier
 * Return: chars to be printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length, width, flags, padd, extra_c, padd_start));
}

/*****print non printable******/
/**
 * print_non_printable - Prints ascii codes in hexa of non printab
 * chars
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size specifier
 * Return: chars to be printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int x = 0, offset = 0;
	char *string = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[x] != '\0')
	{
		if (is_printable(string[x]))
			buffer[x + offset] = string[x];
		else
			offset += append_hexa_code(string[x], buffer, x + offset);
		x++;
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}

/******************* print reverse **********/

/**
 * print_reverse - print reverse string
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: get width
 * @precision: precision specs
 * @size: size specifier
 * Return: chars to be printed
 */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *string;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (i = 0; string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = string[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**********************print a string in rot13*****************/
/**
 * print_rot13string - prints a string in rot13
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size specifier
 * Return: number of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char x;
	char *string;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (i = 0; string[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == string[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}

		}
		if (!in[j])
		{
			x = string[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
