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
		if (*format != '%')
		{
			_putchar(*format);
			count++;
			format++;
		}
		else
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
					char *str = va_arg(args, char *);
					
					while (*str)
					{
						_putchar(*str);
						count++;
						str++;
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
				{
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
				}
			}
			format++;
		}
	}
	va_end(args);
	return (count);
}
