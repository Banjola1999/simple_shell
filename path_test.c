#include "shell.h"

/**
* path_check - check for path
* @path: tokenized path
* @command: user command
*
* Return: path
*/
char *path_check(char **path, char *command)
{
	int i = 0;
	char *chk;

	for (i = 0; path[i] != NULL; i++)
	{
		chk = _path_(path[i], command);
		if (access(chk, F_OK | X_OK) == 0)
			return (chk);
		free(chk);
	}
	return (NULL);
}
