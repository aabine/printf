#include "main.h"

/**
 * handle_non_printable - handles non-printable characters
 * @args: argument list
 * Return: number of characters printed
 */

int handle_non_printable(va_list args)
{
    char c = va_arg(args, int);

    if (c >= 32 && c <= 126)
        write(1, &c, sizeof(char));
    else
        write(1, ".", sizeof(char));

    write(1, "\n", sizeof(char));

    va_end(args);

    return (0);
}