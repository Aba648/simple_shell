#include "main.h"
/**
 * _myenv -  prints the current environment
 * @var: variable.
 * Return: result.
 */
char *_myenv(char *var)
{
	int i;
	char *tmp, *key;
	char *value, *env;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

int main()
{
	printf("%s\n", _myenv("PATH"));
	return (0);
}

