#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
{
    static char buf[1024];
    static int buf_pos = 0;

    buf[buf_pos++] = c;

    if (buf_pos == sizeof(buf) || c == '\n') {
        write(1, buf, buf_pos);
        buf_pos = 0;
    }

    return (1);
}
