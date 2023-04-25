#include "main.h"

/**
 * itob - transform integer value to binary
 * @list: integer to be transformed
 * Return: transformed int
 */

char *itob(va_list list)
{
	int k = 0, twos = 1;
	int i, k;
	char *s;

	k = va_arg(list, int);
	i = k;

	/* use malloc for mem allocation */
	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);

	/* account for negative numbers with '1' at index 0 */
	if (k < 0)
	{
		s[0] = 1 + '0';
		k++;
		k *= -1;
		i *= -1;
	}

	/* establishing highest power of 2 */
	while (k > 1)
	{
		k /= 2;
		twos *= 2;
	}

	/* carry out div and store in binary */
	while (twos > 0)
	{
		s[k++] = (i / twos + '0');
		i %= twos;
		twos /= 2;
	}
	s[k] = '\0';

	return (s);
}
