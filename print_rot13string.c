#include "main.h"

//**
 * print_rot13 - prints a rot13-encoded string
 * @args: argument list containing a char *
 *
 * Return: number of characters printed
 */
int print_rot13(va_list args)
{
    const char *alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    int i, count = 0;
    const char *s = va_arg(args, const char *);
    char hash[128] = {0};
    char out[sizeof(hash)] = {0};
    int out_pos = 0;

    if (s == NULL)
        s = "(null)";

    for (i = 0; i < 52; i++)
        hash[(unsigned char) alph[i]] = rot13[i];

    for (i = 0; s[i]; i++)
    {
        char c = hash[(unsigned char) s[i]];
        out[out_pos++] = c ? c : s[i];
    }

    count = write(STDOUT_FILENO, out, out_pos);
    if (count < 0)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    return count;
}