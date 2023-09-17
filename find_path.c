#include "main.h"
/**
 * _myenv -  prints the current environment
 * @environ: variable.
 * Return: result.
 */
char *_myenv(char *var)
{
	char *atm , *key , *value , *env ;
	int i ;
	for (i=0; environ[i] ; i++)
	{
		atm = strdup(environ[i]);
		key = strtok(atm,"=");
		if (strcmp(key,var)==0)
		{
			value = strtok(NULL , "\n");
			env = strdup(value);
			free(atm);
			return (env);
		}
		free(atm);
		atm=NULL;
	}
	return (NULL);
}
