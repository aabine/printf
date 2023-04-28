#include "main.h"

/**
 * handle_integer - prints a sequence of integers
 * @args: argument list
 * Return: number of characters printed
 */
int handle_integer(va_list args)
{
    int numbers, sum, count = 0, i, powof, length;
    numbers = va_arg(args, int);

    if (numbers <= 0)
        return (0); /* nothing to print */

    for (i = 1; i <= numbers; i++)
    {
        powof = 1;
        sum = 0;
        while (powof <= i)
        {
            sum += powof;
            powof *= 2;
        }
        length = count_digits(sum);
        count += length + 1; /* increment count for each number and space */

        if (i > 1) /* add space before all but the first number */
            write(1, " ", 1);

        print_number(sum, length);
    }
    write(1, "\n", 1);
    count++; /* increment count for newline */
    return (count);
}

/**
 * count_digits - counts the number of digits in an integer
 * @n: integer to count digits of
 * Return: number of digits
 */
int count_digits(int n)
{
    int digits = 0;
    while (n > 0)
    {
        digits++;
        n /= 10;
    }
    return (digits);
}

/**
 * print_number - prints an integer with leading zeros
 * @n: integer to print
 * @length: total length of the output
 */
void print_number(int n, int length)
{
    char buf[10]; /* temporary buffer for converting digits to characters */
    int i;

    for (i = length - 1; i >= 0; i--)
    {
        buf[i] = n % 10 + '0';
        n /= 10;
    }
    write(1, buf, length);
}
