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
	char c;

	while ((ch = *format++) != '\0')
	{
		if (ch != '%')
		{
			putchar(ch);
			count++;
		}
		else
		{
			cha = *format++;

			switch (ch)
			{
				case 'c':
					ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				case 's':
					char *str va_arg(args, char*);
					
					while (*str != '\0')
					{
						putchar(*str);
						count++;
						str++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(ch);
					count += 2;
					break;
			}
		}
	}
	va_end(args);
	return (count);
}
