#include "main.h"

/**
 * print_char - Help function to print a character
 * @arg: The argument containing the character to print
 *
 * Return: Numb of char print (1)
 */
int print_char(va_list arg)
{
	char c = (char)va_arg(arg, int);

	putchar(c);
	return (1);
}

/**
 * print_string - Help function to print a string
 * @arg: The argument containing the string to print
 *
 * Return: Number of char printed (excluding the null byte)
 */
int print_string(va_list arg)
{
	const char *s = va_arg(arg, const char *);
	int printed_characters = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s != '\0')
	{
		putchar(*s);
		s++;
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
	int n = va_arg(arg, int);
	int division = 1;
	int len = 0;
	unsigned int num;

	if (n < 0)
	{
		putchar('-');
		len++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num == 0)
	{
		putchar('0');
		return (len + 1);
	}

	while (num / division > 9)
		division *= 10;

	while (division != 0)
	{
		putchar('0' + num / division);
		len++;
		num %= division;
		division /= 10;
	}

	return (len);
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

