#include "main.h"
#include <inttypes.h>

static const char hex_digits[] = "0123456789abcdef";

/**
 * handle_pointer - handles pointer conversion
 * @args: argument list
 *
 * Return: number of digits printed
 */
int handle_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    uintptr_t addr = (uintptr_t) ptr;
    char buf[BUFF_SIZE];  /* max 16 hex digits, plus "0x" prefix and null terminator */
    int count = 0, i;

    /* format pointer as hexadecimal string */
    for (i = 15; i >= 0; i--) {
        buf[i] = hex_digits[addr & 0xf];
        addr >>= 4;
    }
    buf[BUFF_SIZE] = '\0';

    /* strip leading zeros */
    while (buf[count] == '0' && count < 14)
        count++;

    /* write "0x" prefix and the rest of the buffer */
    buf[count++] = '0';
    buf[count++] = 'x';

    /* Write the result to standard output */
    int result = write(STDOUT_FILENO, buf + count - 2, sizeof(buf) - count + 1);
    if (result < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    return result;
}