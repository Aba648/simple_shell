#include "main.h"
/**
 *  _builtin - check if a given command is one of the built-in commands
 *  @cmd: string representing the command to be checked
 *  Return: 0
 */
int _builtin(char *cmd)
{
	char *builts[] = {"exit", "env", "setenv", "cd", NULL};
	int j;

        for (j = 0; builts[j]; j++)
	{
		if (_strcmp(cmd, builts[j]) == 0)
			return (1);
	}
	return (0);
}

/**
 * set_built - env  Statue Shell
 * @cmd: Command
 * @argv:Name
 * Return: Exit
 */
void set_builtin(char **cmd, char **av, int *status, int idx)
{
	(void) av;
	(void) idx;
	if (_strcmp(cmd[0], "exit") == 0)
		_myexit(cmd, status);
	else if (_strcmp(cmd[0], "env") == 0)
		display_env(cmd, status);
}
/**
 * _myexit - exits the shell
 * @cmd: command
 * @status: input
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit
 */
void _myexit(char **cmd, int *status)
{
	_free(cmd);
	exit(*status);
}
/**
 * display_env - prints the current environment
 * @cmd: the command
 * @status: input
 * Return: void
 */
void display_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	_free(cmd);
	*status = 0;
}
