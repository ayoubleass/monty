#include "monty.h"
/**
 * _getline - Read a line from a file stream
 * @lineptr: A pointer to the buffer where the line is stored
 * @n: A pointer to the size of the buffer
 * @stream: The file stream to read from
 * Return:
 * On success, the number of characters read is returned. On failure,
 * -1 is returned, and the buffer and size remain unchanged.
 */



size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t size  = 0;
	size_t buff_size = 126;
	char  c;

	if (!lineptr || !n)
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(buff_size);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (size >= buff_size)
		{
			*lineptr = realloc(*lineptr, buff_size * 2);
			if (*lineptr == NULL)
				return (-1);

		}
		(*lineptr)[size++] = (char)c;
	}
	if (size == 0)
		return (-1);
	*n = buff_size;
	return (size);
}
