#include "main.h"

#define BUFFER_SIZE 1024

/**
 * struct s_buffer - Buffer struct
 * @buff: Pointer to buffer
 * @pos: Current position in buffer
 */
typedef struct s_buffer
{
    char buff[BUFFER_SIZE];
    size_t pos;
} t_buffer;

/**
 * flush_buffer - Writes contents of buffer to output
 * @buffer: Pointer to buffer
 */
void flush_buffer(t_buffer *buffer)
{
    write(1, buffer->buff, buffer->pos);
    buffer->pos = 0;
}

/**
 * handle_char - Handles a character argument
 * @args: Argument list
 * @buffer: Pointer to buffer
 *
 * Return: 1
 */
int handle_char(va_list args, t_buffer *buffer)
{
    char c;

    c = va_arg(args, int);
    if (buffer->pos >= BUFFER_SIZE)
        flush_buffer(buffer);
    buffer->buff[buffer->pos++] = c;
    return (1);
}

/**
 * print_percent - Handles a percent character
 * @buffer: Pointer to buffer
 *
 * Return: 1
 */
int print_percent(t_buffer *buffer)
{
    char c;

    c = '%';
    if (buffer->pos >= BUFFER_SIZE)
        flush_buffer(buffer);
    buffer->buff[buffer->pos++] = c;
    return (1);
}
