#include "main.h"
#include <unistd.h>

/**
 * print_unsigned - prints an unsigned integer
 * @args: argument list
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int len = 1, powof = 1, digits;
    char buf[10]; /* temporary buffer for converting digits to characters */
    int buflen; /* length of the temporary buffer */

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }

    /* calculate the number of digits in the input */
    while (n / powof >= 10)
    {
        powof *= 10;
        len++;
    }

    /* output leading zeros */
    while (len > 1)
    {
        buf[--len] = '0';
        write(1, &buf[len], 1);
    }

    /* output the actual number */
    while (powof > 0)
    {
        digits = n / powof;
        buf[0] = digits + '0';
        write(1, buf, 1);
        n %= powof;
        powof /= 10;
    }

    write(1, "\n", 1);
    return (0);
}
