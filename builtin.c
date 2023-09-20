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
 * set_builtin - env  Statue Shell
 * @cmd: Command
 * @av:Name
 * @status: input
 * @idx:input
 * Return: Exit
 */
void set_builtin(char **cmd, char **av, int *status, int idx)
{
	if (_strcmp(cmd[0], "exit") == 0)
		_myexit(cmd, av, status, idx);
	else if (_strcmp(cmd[0], "env") == 0)
		display_env(cmd, status);
}
/**
 * _myexit - exits the shell
 * @cmd: command
 * @status: input
 * @av: input
 * @idx: input
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit
 */
void _myexit(char **cmd, char **av, int *status, int idx)
{
	int exit1 = (*status);
	char *index;
	char m[] = ": exit: Illegal number";

	if (cmd[1])
	{
		if (positive_num(cmd[1]))
		{
			exit1 = _atoi1(cmd[1]);
		}
		else
		{
			index = _atoi(idx);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, m, _strlen(m));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			_free(cmd);
			(*status) = 2;
			return;
		}
	}
	_free(cmd);
	exit(exit1);
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
