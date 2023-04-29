#include "main.h"

/**
 * print_rot13 - prints a rot13-encoded string
 * @args: argument list containing a char *
 *
 * Return: number of characters printed
 */
int handle_rot13(va_list args)
{
    const char *s = va_arg(args, const char *);
    int count = 0;

    if (s == NULL)
        s = "(null)";

    for (; *s; s++)
    {
        char c = *s;

        if (c >= 'A' && c <= 'Z')
            c = ((c - 'A') + 13) % 26 + 'A';
        else if (c >= 'a' && c <= 'z')
            c = ((c - 'a') + 13) % 26 + 'a';

        count += write(STDOUT_FILENO, &c, 1);

        if (count < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    return count;
}
