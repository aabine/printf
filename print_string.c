#include "main.h"
#include <errno.h>

/**
 * print_string - prints string
 * @args: va_list containing the string to be printed
 * Return: number of characters printed
 */
int handle_string(va_list args)
{
  char *my_str;
  int len, ret;

  if (args == NULL)
    return (-1);

  my_str = va_arg(args, char *);
  if (my_str == NULL)
    my_str = "(null)";

  len = strlen(my_str);

  ret = write(1, my_str, len);
  if (ret != len)
  {
    perror("write");
    return (-1);
  }

  return (len);
}
