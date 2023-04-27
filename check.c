#include "shell.h"

/**
 * checker - checks if a command is a built-in function or not
 * @cmd: tokenized user input
 * @buf: line from getline function
 * Return: 1 if command executed, 0 if not
 */
int checker(char **cmd, char *buf)
{
	if (builtins(cmd, buf))
	return (1);

	if (cmd[0][0] == '/')
	{
	exec(cmd[0], cmd);
	return (1);
	}

	return (0);
}
