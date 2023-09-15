#include "main.h"
/**
 * execute_cmd - Execute a command using fork and execve.
 * @cmd: An array of strings representing the command and its arguments.
 * @argv: Unused parameter.
 * Return: Returns -1 .
 **/
int execute_cmd(char **cmd, char **argv)
{
	pid_t child;
	int status;
	(void) argv;
	child = fork();
	if (child == -1)
	{
		perror("fork");
		return (1);
	}
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror("argv[0]");
			_free(cmd);
			exit(EXIT_FAILURE);
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
