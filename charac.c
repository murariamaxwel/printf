#include "main.h"
/**
 * print_c - returns a string based on char
 * @list: character under consideration
 * Return: transformed char
 */
char *print_c(va_list list)
{
	char *t;
	char c;

	c = va_arg(list, int);

	if (c == 0)
		c = '\0';

	t = malloc(sizeof(char) * 2);
	if (t == NULL)
		return (NULL);
	t[0] = c;
	t[1] = '\0';

	return (t);
}
