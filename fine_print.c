#include "main.h"

/**
 * _putchar - function prototype
 *
 * @format: args to enter
 * Return: 0
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
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
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				char buffer[32];
				int digits = _itoa(num, buffer, 10);

				for (int i = 0; i < digits; ++i)
				{
					_putchar(buffer[i]);
					count++;
				}
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
			format++;
		}
	}
	va_end(args);
	return (count);
}
