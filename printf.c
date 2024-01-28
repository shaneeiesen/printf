#include "main.h"

/**
 * _print - function prototype
 *
 * @format: arguments count
 * Return: 0
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	char ch, next_ch;

	while ((ch = *format++) != '\0')
	{
		if (ch != '%')
		{
			putchar(ch);
			count++;
		}
		else
		{
			next_ch = *format++;

			switch (next_ch)
			{
				case 'c':
				{
					char c = (char) va_arg(args, int);

					putchar(c);
					count++;
					break;
				}
				case 's':

				{
					char *str = va_arg(args, char*);

					while (*str != '\0')
					{
						putchar(*str++);
						count++;
					}
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(next_ch);
					count += 2;
					break;
			}
		}
	}
	va_end(args);
	return (count);
}
