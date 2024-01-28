#include "main.h"

/**
 * _print - function prototype
 *
 * @format: arguments count
 * Return: 0
 */

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++) {
        if (*p != '%') {
            fputc(*p, stdout);
            count++;
            continue;
        }

        switch (*++p) {
            case 'c': ;
                char c = (char) va_arg(args, int);
                fputc(c, stdout);
                count++;
                break;
            case 's': ;
                const char *s = va_arg(args, char*);
                if (s == NULL) {
                    s = "(null)";
                }
                for (const char *str = s; *str != '\0'; str++) {
                    fputc(*str, stdout);
                    count++;
                }
                break;
            case '%':
                fputc('%', stdout);
                count++;
                break;
            default:
                fputc('%', stdout);
                fputc(*p, stdout);
                count += 2;
                break;
        }
    }

    va_end(args);
    return count;
}
