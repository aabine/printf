#include "main.h"

/**
 * print_string - prints string
 * @s: string to be printed
 * Return: i
 */
int print_string(va_list args)
{
  char *my_str;
  int len;
  my_str = va_arg(args, char *);
  if (my_str == NULL)
    my_str = "(null)";

  // Calculate string length
  for (len = 0; my_str[len]; len++)
    ;

  // Write string to standard output
  write(1, my_str, len);

  return (len);
}
