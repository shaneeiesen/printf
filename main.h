#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int _printf(const char *format, ...);
int _putchar(char c);
int _putstr(char *s);
int _itoa(int num, char *buffer, int base);


#endif
