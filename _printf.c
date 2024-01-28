#include "main.h"


/**
 * _printf- func t print data ffff
 *
 * @format: character indetifier dd
 *
 * Return: numb of char printeddd 
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_characters = 0;
	int (*print_func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			print_func = get_print_func(*format);
			if (print_func != NULL)
				printed_characters += print_func(args);
			else
			{
				putchar('%');
				putchar(*format);
				printed_characters += 2;
			}
		}
		else
		{
			putchar(*format);
			printed_characters++;
		}

		format++;
	}

	va_end(args);

	return (printed_characters);
}

