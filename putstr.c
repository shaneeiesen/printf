#include <unistd.h>
#include "_PUTCHAR.H"

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
