#include "main.h"
/**
 * path_cmd -  Search PATH of an excutable command
 * cmd: Parsed Input
 * Return: NULL
 */
char *getpath(char *cmd)
{
	int i;
	char *path, *command, *var;
	struct stat am;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &am) == 0)
				return (_strdup(cmd));
			else
				return (NULL);
		}
	}
	path = getenv("PATH");
		if (!path)
			return (NULL);
	var = strtok(path, ":");
		while (var)
		{
			command = malloc(_strlen(var)+ _strlen(cmd) +2);
			if(command)
			{
				_strcpy(command, var);
				_strcat(command, "/");
				_strcat(command, cmd);
				if (stat(command, &am) == 0)
				{
					free(path);
					return(command);
				} 
				free(command);
				command = NULL;
				var = strtok(NULL, ":");
			}
		}
		return (NULL);
}
