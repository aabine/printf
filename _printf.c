#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*get_handler)(va_list);
	unsigned int format_pos = 0;
	char buffer[BUFF_SIZE * 10] = {0};
	int buffer_pos = 0; /* position in buffer */

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);

	while (format[format_pos])
	{
		while (format[format_pos] != '%' && format[format_pos] != '\0')
		{
			buffer[buffer_pos++] = format[format_pos++];
			if (buffer_pos >= sizeof(buffer))
			{
				buffer_pos = 0;
			}
		}

		if (format[format_pos] == '\0')
			break;

		switch (format[format_pos + 1])
		{
			case 'd':
			case 'i':
				get_handler = handle_integer;
				break;
			case 'c':
				get_handler = handle_char;
				break;
			case 's':
				get_handler = handle_string;
				break;
			case 'x':
			case 'X':
				get_handler = handle_hex;
				break;
			case 'o':
				get_handler = handle_octal;
				break;
			case 'b':
				get_handler = handle_binary;
				break;
			case 'u':
				get_handler = handle_unsigned;
				break;
			case 'p':
				get_handler = handle_pointer;
				break;
			case 'r':
				get_handler = handle_reverse;
				break;
			case 'R':
				get_handler = handle_rot13;
				break;
			default:
				if (format[format_pos])
					get_handler = handle_non_printable;
				else
					break;

				buffer[buffer_pos++] = format[format_pos];
				buffer[buffer_pos++] = format[format_pos + 1];
				if (buffer_pos >= sizeof(buffer))
				{
					buffer_pos = 0;
				}
				format_pos += 2;
				continue;
		}

		buffer_pos += vsnprintf(&buffer[buffer_pos], sizeof(buffer) - buffer_pos, &format[format_pos], args);
		format_pos += 2;

		if (get_handler)
			buffer_pos += get_handler(args);

		if (buffer_pos >= sizeof(buffer))
		{
			buffer_pos = 0;
		}

		write(1, buffer, buffer_pos);

		buffer[buffer_pos] = '\0';
	}

	
	va_end(args);

	if (buffer_pos > 0)
		fwrite(buffer, buffer_pos, 1, stdout);

	return (format_pos);
}