#include "main.h"

/**
 * _itos - transforms int to str
 * @divis: mult of ten
 * @length: len
 * @n: num to transform
 * Return: transformed num
 **/
char *_itos(int divis, int length, int n)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * length + 2);
	if (str == NULL)
		return (NULL);

	if (n < 0) /* putting -ve values into consideration */
	{
		str[0] = '-';
		i++;
	}
	while (n < 0) /* transforming num to str */
	{
		str[i] = ((n / divis) * -1 + '0'); /* *-1 handles lowest int */
		n = n % divis;
		divis /= 10;
		i++;
	}
	while (divis >= 1) /* case scenario for +ve values */
	{
		str[i] = ((n / divis) + '0');
		n = n % divis;
		divis /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * print_d - fetches len
 * @list: arg
 * Return: str
 **/
char *print_d(va_list list)
{
	int length, divis, n, temp;

	n = va_arg(list, int);
	temp = n;
	length = 0;
	divis = 1;

	if (n == 0) /* case for zero */
	{
		length++;
		return (_itos(divis, length, n));
	}

	while (temp != 0) /* find multiple of ten to diviside */
	{
		length += 1;
		if (length > 1)
			divis *= 10;
		temp /= 10;
	}

	return (_itos(divis, length, n));
}
