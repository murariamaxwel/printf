#include "main.h"

/**
 * itooct - transform integer to octal
 * @list: integer to transorm
 * Return: transformed int
 */

char *itooct(va_list list)
{
	int k = 0, eights = 1;
	int i, k;
	char *s;

	k = va_arg(list, int);
	i = k;

	/* perform memory allocation */
	s = malloc(sizeof(char) * 12);
	if (s == NULL)
		return (NULL);

	if (k < 0)
	{
		s[0] = 1 + '0';
		k++;
		k *= -1;
		i *= -1;
	}

	/* determination of highest power */
	while (k > 1)
	{
		k /= 8;
		eights *= 8;
	}

	/* division */
	while (eights > 0)
	{
		s[k++] = (i / eights + '0');
		i %= eights;
		eights /= 8;
	}
	s[k] = '\0';

	return (s);
}
