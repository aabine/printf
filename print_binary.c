#include <stdarg.h>
#include <unistd.h>

int handle_binary(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int bit_count = 0;
    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }
    bit_count = 1;
    while ((num >> bit_count) != 0)
        bit_count++;
    int i;
    for (i = bit_count - 1; i >= 0; i--) {
        char bit = ((num >> i) & 1) ? '1' : '0';
        write(1, &bit, 1);
    }
    return bit_count;
}
