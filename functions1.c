#include "main.h"

/*************************print unsigned number**************/

/**
 * print_unsigned - prints a unsigned number
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size specs
 * Return: chars to be printed
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/******************* print unsigned number in octal***************/

/**
 * print_hexadecimal - prints an unsigned number in hexdecimal nota
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size specs
 * Return: char to be printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

/*************prints unsigned number in upper hexadecimal*********/

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecima
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size specs
 * Return: chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

/************prints hexadecimal number in lower and upper*******/

/**
 * print_hexa - prints hexadecimal num in lower and uppercase
 * @types: list of arguments
 * @map_to: array of values to map the number
 * @buffer: buffer array
 * @flags: calc active flags
 * @flag_ch: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size spec
 * @size: sizes specs
 * Return: chars to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
