#include <unistd.h>
#include <stdlib.h>

/**
 * print_number - function prototype
 *
 * @n: numbers
 * Return: 0
 */


int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;

		if (n == -2147483648)
		{
			count += print_number(-(n / 10));
			_putchar('8');
			count++;
			return (count);
		}
		n = -n;
	}

	if (n / 10)
	{
		count += print_number(n / 10);
	}

	_putchar(n % 10 + '0');
	count++;

	return (count);
}
