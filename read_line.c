#include "main.h"
/**
 * read_line - Reads a line of text from standard input.
 * Return: a pointer.
 */
char *read_line(void)
{
	char *lineptr = NULL;
	size_t buffer_size = 0;
	ssize_t m = 0;

	m = getline(&lineptr, &buffer_size, stdin);
	if (m == -1)
	{
		free(lineptr);
		return (NULL);
	}
	return (lineptr);
}

