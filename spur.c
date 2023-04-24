#include "main.h"

/**
 * cb_overflow - performs a check of buffer space and,
 * displays all items within the buffer
 * @buffer: this arg holds the string of concern
 * @len: represents position in a buffer
 * Return: len
 */
int cb_overflow(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}

/**
 * _printf - customized printf function
 * @format: represents initial str
 * Return: strs
 */
int _printf(const char *format, ...)
{
	int len = 0, total_len = 0, i = 0, j = 0;
	va_list list;
	char *buffer, *str;
	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* format copier */
		{
			len = cb_overflow(buffer, len);
			buffer[len++] = format[i++];
			total_len++;
		}
		else /* if %, find function */
		{
			i++;
			if (format[i] == '\0') /* how to handle a single endi,, % */
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%') /* handle double %'s */
			{
				len = cb_overflow(buffer, len);
				buffer[len++] = format[i];
				total_len++;
			}
			else
			{
				f = get_func(format[i]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					len = cb_overflow(buffer, len);
					buffer[len++] = '%'; total_len++;
					buffer[len++] = format[i]; total_len++;
				}
				else /* return str */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = cb_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = cb_overflow(buffer, len);
						buffer[len++] = str[j];
						total_len++; j++;
					}
					free(str);
				}
			} i++;
		}
	}
	write_buffer(buffer, len, list);
	return (total_len);
}

/**
 * main - repreents a sample of the main prog
 * Return: 0 to signify success
 */
int main(void)
{
	_printf("\n\n\nHere's some examples of what you could do with this custom_printf function!\n\n\n");
	sleep(1);
	_printf("\nPrinting Strings, Characters, and Numbers...... %s %c%drld\n\n", "Hello", 'W', 0);
	sleep(1);
	_printf("Printing Reverse...... %r \n\n", "Hello");
	sleep(1);
	_printf("Printing Binary (base 2)...... %b \n\n", "Hello");
	sleep(1);
	_printf("Printing Octal (base 8)...... %o \n\n", "Hello");
	sleep(1);
	_printf("Printing Rot13 (encrypt)...... %R \n\n", "Hello");
	sleep(1);
	_printf("\n\n             = )                  \n\n\n");
	return (0);
}
