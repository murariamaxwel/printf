#include "main.h"

/**
 * r_string - writes a str in reverse
 * @list: str to be reversed
 * Return: the str that has been reversed
 */

char *r_string(va_list list)
{
        char *r;
	char *str;
	int i = 0, len, j;

	str = va_arg(list, char *); /* handle storage of arg */
	if (str == NULL)
		str = ")llun(";

	len = _strlen(str);

	r = malloc(sizeof(char) * (len + 1)); /* handle memory allocation */
	if (r == NULL)
		return (NULL);

	for(j = (len - 1); j >= 0; j--) /* handle storage of reversed string */
	{
		r[i++] = str[j];
	}
	r[i] = '\0';

	return (r);
}
