#include "main.h"

/**
 * print_binary - print binary
 * @args: arguments
 * Return: number of bits
 */

int handle_binary(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int bit_count = 0;
    for (int i = 31; i >= 0; i--) {
        char bit = ((num >> i) & 1) ? '1' : '0';
        write(1, &bit, 1);
        bit_count++;
    }
    return bit_count;
}