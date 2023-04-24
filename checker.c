#include "shell.h"

/**
 * checker - checks whether the command is a built-in function or an executable file
 * @cmd: tokenized user input
 * @buf: line derived from getline function
 *
 * Return: 1 if cmd executed, 0 if cmd is not executed
 */
int checker(char **cmd, char *buf)
{
    /* check if the command is a built-in function */
	if (builtins(cmd, buf))
	{
	return (1);
	}

    /* if it's not a built-in, check if it's an executable file */
	if (access(cmd[0], X_OK) == 0)
	{
	exec(cmd[0], cmd);
	return (1);
	}

	return (0);
}
