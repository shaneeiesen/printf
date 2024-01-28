#include "main.h"

/**
*This is a printf function that handles %d and %i format specifiers
*@format - use format specifiers e.i %d and %i to print interger values
*Return: Determines the charater/integers printed
*/

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int count = 0;

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'd':
case 'i':
count += printf("%d", va_arg(args, int));
break;
default:
break;
}
}
else
{

count += _putchar(*format);

}

format++;
}

va_end(args);

return (count);
}
