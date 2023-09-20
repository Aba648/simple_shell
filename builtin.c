#include "main.h"

int _builtin(char *cmd)
{
    int i;
    char *builts[] = {"exit", "env", "setenv", "cd", NULL};

    for (i = 0; builts[i]; i++)
    {
        if (_strcmp(cmd, builts[i]) == 0)
            return (1);
    }
    return (0);
}

/**
 * set_built - Handle built-in commands
 * @cmd: Command
 * @av: Name
 * @status: Status
 * @idx: Index
 */
void set_built(char **cmd, char **av, int *status, int idx)
{
    if (_strcmp(cmd[0], "exit") == 0)
        _myexit(cmd, status);
    else if (_strcmp(cmd[0], "env") == 0)
        display_env(cmd, status);
}

/**
 * _myexit - Exits the shell
 * @cmd: Command
 * @status: Status
 */
void _myexit(char **cmd, int *status)
{
    _free(cmd);
    exit(*status);
}

/**
 * display_env - Prints the current environment
 * @cmd: Command
 * @status: Status
 */
void display_env(char **cmd, int *status)
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    _free(cmd);
    *status = 0;
}

