#include "main.h"

/**
 * handle_hex - prints lowercase or uppercase hexadecimal
 * @num: the number to print
 * @uppercase: flag indicating whether to use uppercase or lowercase letters
 * Return: the number of characters printed
 */

int handle_hex(va_list args)
{
    static const char digits[] = "0123456789abcdef0123456789ABCDEF";
    char buf[BUFF_SIZE];
    char *end = &buf[BUFF_SIZE - 1];
    int count = 0;
    unsigned int uppercase = va_arg(args, unsigned int);
    unsigned int num = va_arg(args, unsigned int);

    // Add padding for width specifier, if present
    int width = 0;
    if ((width = va_arg(args, int)) > BUFF_SIZE - 1) {
        width = BUFF_SIZE - 1;
    }

    // Compute hex digits in reverse order
    while (num && end > buf) {
        *--end = digits[num & 0xf];
        num >>= 4;
    }

    // Add padding for width specifier, if present
    while (count < width - (buf + BUFF_SIZE - end)) {
        if (write(STDOUT_FILENO, " ", 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        count++;
    }

    // Write hex digits in forward order
    while (end < &buf[BUFF_SIZE]) {
        if (write(STDOUT_FILENO, end++, 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        count++;
    }

    return count;
}