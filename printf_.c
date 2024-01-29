#include <stdarg.h> // for variable arguments
#include <unistd.h> // for write function


int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _putstr(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        _putchar(s[i]);
        i++;
    }
    return (i);
}


int _printf(const char *format, ...)
{
    int count = 0;
    int i = 0;
    va_list args;
    char *s;
    char c;

    
    va_start(args, format);

    while (format[i] != '\0')
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
                // If the next character is 'c', get a character argument and print it
                case 'c':
                    c = va_arg(args, int); // cast the argument to int
                    _putchar(c);
                    count++;
                    break;
                // If the next character is 's', get a string argument and print it
                case 's':
                    s = va_arg(args, char *); // cast the argument to char *
                    count += _putstr(s); // print the string and add its length to the count
                    break;
                // If the next character is '%', print a literal '%' character
                case '%':
                    _putchar('%');
                    count++;
                    break;
                // If the next character is anything else, print it as it is
                default:
                    _putchar(format[i]);
                    count++;
                    break;
            }
        }
        // Increment the index to move to the next character
        i++;
    }

    // End the variable argument list
    va_end(args);

    // Return the number of characters printed
    return (count);
}

