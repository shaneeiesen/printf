#include "main.h"

/**
 * _printf - function prototype
 *
 * @format: agrs passed
 * Return: always return 0
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
					char ch = va_arg(args, int);

					if (_putchar(ch) < 0)
					{
						return (-1);
					}
					count++;
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char*);

					while (*str)
					{
						if (_putchar(*str++) < 0)
						{
							return (-1);
						}
						count++;
					}
				}
					break;
				case '%':
				{
					if (_putchar('%') < 0)
					{
						return (-1);
					}
					count++;
					break;
				}
				default:
				{
					if (_putchar('%') < 0 || _putchar(*format) < 0)
					{
						return (-1);
					}
					count += 2;
					break;
				}
			}
		}
		else
		{
			if (_putchar(*format) < 0)
			{
				return (-1);
			}
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
