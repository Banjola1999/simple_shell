#include "shell.h"

/**
 * checker - checks if a command is a built_in or not built_in
 * @cmd: tokenized input
 * @buf: getline line
 * Return: 1 (Success), 0 (Unsuccessful)
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
