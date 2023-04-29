#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

#define BUFF_SIZE 2048 // Define a constant for buffer size

// Define a struct for format specifiers
typedef struct specifier
{
	const char *name;
	int (*handler)(va_list);
} f_spec;



int _printf(const char *format, ...);

int precision(va_list args, f_spec spec[], int *count, int *i);
int width(va_list args, f_spec spec[], int *count, int *i);
int flags(va_list args, f_spec spec[], int *count, int *i);
int conversion(va_list args, f_spec spec[], int *count, int *i);



// Declare the handler functions for the format specifiers

int handle_non_printable(va_list args);
int handle_integer(va_list args);
int handle_decimal(va_list args);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_hex(va_list args);
int handle_octal(va_list args);
int handle_binary(va_list args);
int handle_unsigned(va_list args);
int handle_pointer(va_list args);
int handle_reverse(va_list args);
int handle_rot13(va_list args);

#endif
