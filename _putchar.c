#include "main.h"

/**
 * _putchar - writes the char c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * error -1 is return, and err no isset.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
