#include "main.h"
/**
 * get_path - Search path of an excutable command
 * cmd: Parsed Input
 * Return: NULL
 */
char *get_path(char *cmd)
{
	int i;
	char *path, *full_cmd,*diractory;
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
	path = _myenv("PATH");
		if (!path)
			return (NULL);
		diractory = strtok(path, ":");
		while (diractory)
		{
			full_cmd = malloc(_strlen(diractory)+ _strlen(cmd) +2);
			if(full_cmd)
			{
				_strcpy(full_cmd, diractory);
				_strcat(full_cmd, "/");
				_strcat(full_cmd, cmd);
				if (stat(full_cmd , &am) == 0)
				{
					free(path);
					return(full_cmd);
				} 
				free(full_cmd);
				full_cmd = NULL;
				diractory = strtok(NULL, ":");
			}
		}
		free(path);
		return (NULL);
}
