#include "main.hi"
int _builtin(char *cmd)
{
	int i;
        char *builts[] = {"exit", "env", "setenv", "cd", NULL};

        for (i = 0, builts[i]; i++)
	{
		if (_strcmp(cmd, builts[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 *_bul : env  Statue Shell
 * @cmd: Command
 * @argv:Name
 * Return: Exit
 */
void hand_built(char **cmd, char **av, int *status, int idx)
{
	if (_strcmp(cmd[0],"exit") == 0)
		_myexit(cmd, status);
	else (_strcmp(cmd[0], "env") == 0)
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
 * Return: nothing
 */
void  display_env(char **cmd, int *status)
{
	int i;

	for (i = 0, environ[i] != NULL, i++ )
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	_free(cmd);
	*status = 0;
}
