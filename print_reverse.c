#include "main.h"
#include <errno.h>

/*
 * handle_reverse - prints a string in reverse order
 * @args: a va_list containing a char *
 *
 * Return: the number of characters printed
 */
int handle_reverse(va_list args)
{
    /* Get the string argument from the va_list */
    char *str = va_arg(args, char *);

    /* If the string is NULL, print "(llun)" */
    if (str == NULL)
        str = "(nil)";

    /* Get the length of the string */
    int len = strlen(str);

    /* Print the string in reverse order */
    for (int i = len - 1; i >= 0; i--)
    {
        if (write(1, (str + i), 1) == -1)
        {
            /* Handle the error */
            perror("Error printing string");
            return -1;
        }
    }

    /* Return the length of the original string */
    return len;
}
