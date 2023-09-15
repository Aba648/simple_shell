#include "main.h"
/**
 * _free - frees a string of strings
 * @array: string of strings
 */

void _free(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

