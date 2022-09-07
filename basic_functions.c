#include "shell.h"
/**
 * _puts - prints a string
 *
 * @str: points to string to be printed
 */

void _puts(char *str)
{
    int c;
    for (c = 0 ; str[c] != '\0'; c++)
    {
        _putchar(str[c]);
    }
    _putchar('\n');
}

/**
 * _putchar - puts a character on the standard output
 *
 * @c: character to be printed
 * Returns: 0 on success
 */
int _putchar (char c)
{
    return(write(1,&c,1));
}
