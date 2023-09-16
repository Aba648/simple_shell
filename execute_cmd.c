#include "main.h"
/**
 * execute_cmd - Execute a command using fork and execve.
 * @cmd: An array of strings representing the command and its arguments.
 * @av: parameter.
 * Return: Returns -1 .
 **/
int execute_cmd(char **cmd, char **av)
{
	int status;
	pid_t child;
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(av[0]);
			_free(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		_free(cmd);
		status = WEXITSTATUS(status);
	}
	return (status);
}
