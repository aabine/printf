#include "main.h"
#include <unistd.h>

/*
 * handle_percent - prints a percent sign
 * @args: a va_list (unused)
 *
 * Return: the number of characters printed
 */
int handle_percent(va_list __attribute__((unused)) args)
{
    /* Print a percent sign to standard output */
    if (write(1, "%", 1) == -1)
    {
        /* Handle the error */
        perror("Error printing percent sign");
        return -1;
    }

    /* Return the number of characters printed */
    return 1;
}
