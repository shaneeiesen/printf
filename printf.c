#include "main.h"

/**
 * _print - function prototype
 *
 * @format: arguments count
 * Return: 0
 */

int _printf(const char *format, ...)
{
	unsigned int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					char c = va_arg(args, int);

					_putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char*);

					if (str != NULL)
					{
						while (*str)
					{
							_putchar(*str++);
							count++;
					}
					}
					break;
				}
				case '%':
				{

					_putchar('%');
					count++;
					break;
				}
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
