#include "main.h"

/**
 * handle_hex - prints lowercase or uppercase hexadecimal
 * @num: the number to print
 * @uppercase: flag indicating whether to use uppercase or lowercase letters
 * Return: the number of characters printed
 */

int handle_hex(va_list args, const int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    const char *digits = (uppercase ? "0123456789ABCDEF" : "0123456789abcdef");
    char buf[64];
    int i = 0, count = 0;

    do {
        buf[i++] = digits[num % 16];
        num /= 16;
    } while (num);

    // Add padding for width specifier, if present
    int width = 0;
    if ((width = va_arg(args, int)) > i) {
        for (int j = 0; j < (width - i); j++) {
            buf[i++] = ' ';
        }
    }

    for (int j = i - 1; j >= 0; j--) {
        if (write(STDOUT_FILENO, &buf[j], 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        count++;
    }

    return count;
}