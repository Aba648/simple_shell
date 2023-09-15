#include "main.h"
/**
 * tokenizer -  splits the input string into individual tokens.
 * @lineptr: input string.
 * Return: array of pointers.
 */
char **tokenizer(char *lineptr)
{
	char *token = NULL, *lineptr_cpy = NULL;
	char **cmd = NULL, delim[] = " \t\n";
	int cpt = 0, i = 0;

	if (!lineptr)
		return (NULL);
	lineptr_cpy = _strdup(lineptr);
	token = strtok(lineptr_cpy, delim);
	if (!token)
	{
		free(lineptr_cpy);
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, delim);
	}
	free(lineptr_cpy);
	cmd = malloc(sizeof(char *) * (cpt + 1));

	if (!cmd)
	{
		return (NULL);
	}
	token = strtok(lineptr, delim);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(lineptr);
	cmd[i] = NULL;
	return (cmd);
}

