#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>

/**
 * handle_integer - prints a sequence of integers
 * @args: argument list
 * Return: number of characters printed
 */
int handle_integer(va_list args)
{
    int numbers, sum, count = 0, i, length, buf_size, digits;
    char *buf;

    numbers = va_arg(args, int);

    if (numbers <= 0)
        return (0); /* nothing to print */

    buf_size = log10(numbers * (numbers + 1) / 2) + numbers + 1;
    buf = malloc(buf_size);

    sum = 1;
    sprintf(buf, "%d", sum);
    length = log10(sum) + 1;
    count += length;
    for (i = 2; i <= numbers; i++)
    {
        sum += i;
        sprintf(buf + count, " %d", sum);
        length = log10(sum) + 1;
        count += length + 1; /* increment count for each number and space */
    }
    write(1, buf, count);
    write(1, "\n", 1);
    count++; /* increment count for newline */

    free(buf);
    return (count);
}