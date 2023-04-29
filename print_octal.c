#include "main.h"
#include <sys/uio.h>

/**
 * handle_octal - handles octal conversion
 * @args: argument list
 * Return: number of digits printed
 */

int handle_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    unsigned int pow_8 = 1, n = num;
    int count = 0;
    char buf[BUFF_SIZE];

    /*Calculate the maximum power of 8 required to represent the number */
    while (n >>= 3)
        pow_8 = (pow_8 << 3) | 1;

    /* Convert the number to octal and store the result in buf*/
    while (pow_8) {
        buf[count++] = (num >> pow_8) & 7 | '0';
        pow_8 >>= 3;
    }

    /* Write the result to standard output */
    struct iovec iov[1];
    iov[0].iov_base = buf;
    iov[0].iov_len = count;
    int result = writev(STDOUT_FILENO, iov, 1);
    if (result < 0) {
        perror("writev");
        exit(EXIT_FAILURE);
    }

    return result;
}