#include "main.h"

/**
 * _printf - function prototype
 *
 * @format: count number of agrs
 * Return: 0
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int i = 0;
	va_list args;
	char *s;
	char c;

	va_start(args, format);

	while (format[0] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;

			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					count += _putstr(s);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar(format[i]);
					count++;
					break;
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
