#include "main.h"

/**
 * get_func - provides req func
 * @i: specifies the particular func
 * Return: funct ptr
 */
char* (*get_func(char i))(va_list)
{
	int k = 0;

	print keys[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'b', itob},
		{'R', rot13},
		{'r', rev_string},
		{'o', itoOctal},
		{'\0', NULL}
	};

	while (keys[k].id != '\0')
	{
		if (keys[k].id == i)
			return (keys[k].func);
		k++;
	}
	return (NULL);
}

/**
 * create_buff - prepares buffer
 * Return: ptr to buffer
 */
char *create_buff(void)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);
	if (buff == NULL)
		return (NULL);
	return (buff);
}

/**
 * write_buff - displays buffer and frees it
 * @buff: represents the buffer
 * @len: len of str to display
 * @list: va_list
 */
void write_buff(char *buff, int len, va_list list)
{
	char *buff;

	buff = realloc(buff, len); /* realloc to correct size */
	write(1, buff, len); /* print */

	free(buff); va_end(list);
}
