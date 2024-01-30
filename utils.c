#include "main.h"

/**
 * is_printable - evaluates if char is printable
 * @c: char to be evaluated
 * Return: 1 if c is printable, otherwise 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - append ascii in hexadecimal code to buffer
 * @buffer: array
 * @i: index at which to start append
 * @ascii_code: ascii code
 * Return: 3 on success
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* hexa format is always 2 digits*/
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies if char is a digit
 * @c: char to be evaluated
 * Return: 1 if c a digit, otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - casts a numb to the specified size
 * @num: to be casted
 * @size: type to be casted
 * Return: value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - cast a num to the specified size
 * @num: casted num
 * @size: type to be casted
 * Return: value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
