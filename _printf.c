#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int (*handler)(va_list);
    unsigned int count = 0, length = 0;
    char buffer[1024];
    int buffer_pos = 0;

    if (!format)
    {
        return (-1);
    }

    va_start(args, format);

    while (format[count])
    {
        while (format[count] != '%' && format[count] != '\0')
        {
            buffer[buffer_pos++] = format[count++];
            length++;
        }

        if (format[count] == '\0')
            break;

        handler = find_specifier(&format[count + 1]);
        if (handler)
        {
            buffer_pos += vsnprintf(&buffer[buffer_pos], sizeof(buffer) - buffer_pos, &format[count], args);
            length += buffer_pos - (buffer_pos - sizeof(buffer));
            count += 2;
            continue;
        }

        if (format[count + 1] == '\0')
            return (-1);

        buffer[buffer_pos++] = format[count + 1];
        length++;

        if (format[count + 1] == '%')
            count += 2;
        else
            count++;
    }
    va_end(args);

    fwrite(buffer, buffer_pos, 1, stdout);

    return (length);
}

/**
 * find_specifier - finds a specifier
 * @args: argument list
 * Return: handler
 */

int (*find_specifier(const char *args))(va_list)
{

    unsigned int count = 0;

    f_spec formats[] = {
        {"C", handle_non_printable},
        {"%d", handle_integer},
        {"%i", handle_decimal},
        {"%f", handle_float},
        {"%c", handle_char},
        {"%s", handle_string},
        {"%x", handle_hex},
        {"%X", handle_hex},
        {"%o", handle_octal},
        {"%b", handle_binary},
        {"%u", handle_unsigned},
        {"%p", handle_pointer},
        {"%r", handle_reverse},
        {"%R", handle_rot13},
        {NULL, 0}};

    while (formats[count].name)
    {
        if (formats[count].name == (char *)args[0])
        {
            return formats[count].handler;
        }
        count++;
    }
    return NULL;
}