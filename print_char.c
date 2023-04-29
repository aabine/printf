#include "main.h"

int handle_char(va_list args) {
    char c = va_arg(args, int);
    if (c == '\0') {
        return -1; // Null character not allowed
    }

    static char buffer[BUFF_SIZE];
    static int buffer_pos = 0;

    buffer[buffer_pos++] = c;

    if (buffer_pos >= sizeof(buffer)) {
        if (write(STDOUT_FILENO, buffer, sizeof(buffer)) != sizeof(buffer)) {
            return -1; // Error writing to standard output
        }
        buffer_pos = 0;
    }

    return 0;
}

int flush_buffer() {
    static char buffer[BUFF_SIZE];
    static int buffer_pos = 0;

    if (buffer_pos > 0) {
        if (write(STDOUT_FILENO, buffer, buffer_pos) != buffer_pos) {
            return -1; // Error writing to standard output
        }
        buffer_pos = 0;
    }

    return 0;
}
