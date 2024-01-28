#include "main.h"

/**
 * print_char - Helper function to print a character
 * @arg: The argument containing the character to print
 *
 * Return: Number of characters printed (1)
 */
int print_char(va_list arg)
{
	char c = (char)va_arg(arg, int);

	putchar(c);
	return (1);
}

/**
 * print_string - Helper function to print a string
 * @arg: The argument containing the string to print
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int print_string(va_list arg)
{
	const char *s = va_arg(arg, const char *);
	int printed_characters = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	for (; *s != '\0'; s++)
	{
		putchar(*s);
		printed_characters++;
	}

	return (printed_characters);
}

/**
 * print_percent - Helper function to print '%'
 * @arg: The argument list (unused)
 *
 * Return: Number of characters printed (1)
 */
int print_percent(__attribute__((unused)) va_list arg)
{
	putchar('%');
	return (1);
}

/**
 * print_int - Function to print integer
 * @arg: argument(integer) to print
 * Return: the len
 */
int print_int(va_list arg)
{
/**
 *
 *
 */
}

/**
 * get_print_func - pointer to function
 *
 * @c: datatype identifier
 *
 * Description: take 'c' on select the right function
 *
 * Return: one of the functions or NULL
 */
int (*get_print_func(const char c))(va_list)
{
	switch (c)
	{
		case 'c':
			return (print_char);
		case 's':
			return (print_string);
		case '%':
			return (print_percent);
		case 'i':
		case 'd':
			return (print_int);
		default:
			return (NULL);
	}
}

