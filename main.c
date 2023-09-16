#include "main.h"
/**
*main - This is the entry point of the program.
* @ac: Argument count
* @av: Argument vector
* Return: 0 on success, 1 on error.
*/
int main(int ac, char **av)
{
	char *lineptr = NULL;
	char **cmd = NULL;
	int status = 0;
	(void) ac;
	while (1)
	{
		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		lineptr = read_line();
		if (lineptr == NULL)
		{
			if (isatty(STDOUT_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(lineptr);
			exit(status);
		}
		cmd = tokenizer(lineptr);
		if (!cmd || cmd[0] == NULL)
		{
			free(lineptr);
			continue;
		}
		status = execute_cmd(cmd, av);
	}
}

