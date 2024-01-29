#include <unistd.h>

/**
 * _itoa - Internal function to convert an integer to a string
 *
 * @num: number to convert
 * @buffer: buffering
 * base: 10
 * Return: 0
 */

int _itoa(int num, char *buffer, int base)
{
	int digits = 0;

	if (num < 0)
	{
		_putchar('-');
		num *= 1;
		digits++;
	}

	do
	{
		int digit = num % base;
		
		num /= base;
		buffer[digits++] = (char)('0' + digit);
	} while (num > 0);

	buffer[digits] = '\0';
	return (digits);
}
