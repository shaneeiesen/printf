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

					putchar(c);
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
							putchar(*str++);
							count++;
						}
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
