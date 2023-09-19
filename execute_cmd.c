#include "main.h"
/**
 * execute_cmd - Execute a command using fork and execve.
 * @cmd: An array of strings representing the command and its arguments.
 * @av: parameter.
 * @idx: varaible.
 * Return: Returns -1 .
 **/
int execute_cmd(char **cmd, char **av, int idx)
{
	int status;
	char *full_cmd;
	pid_t child;

	full_cmd = get_path(cmd[0]);

	if (!full_cmd)
	{
		display_error(av[0], cmd[0], idx);
		_free(cmd);
		return (127);

	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			_free(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		_free(cmd);
		free(full_cmd);
		full_cmd = NULL;
		status = WEXITSTATUS(status);
	}
	return (status);
}
