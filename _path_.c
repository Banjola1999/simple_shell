#include "shell.h"

/**
* _path_ - adds path to command
* @path: path of command
* @command: user entered command
*
* Return: buffer containing command with path on success
* NULL on failure
*/
char *_path_(char *path, char *command)
{
	char *buf;
	size_t i, j;

	if (command == NULL)
		command = "";
	if (path == NULL)
	path = "";

	buf = malloc(sizeof(char) * (string_length(path) +
	string_length(command) + 2));
	if (buf == NULL)
		return (NULL);

	for (i = 0; path[i]; i++)
		buf[i] = path[i];

	buf[i] = ((i == 0 || path[i - 1] != '/') ? '/' : '\0');
	for (j = 0; command[j]; j++)
		buf[i + j + 1] = command[j];

	buf[i + j + 1] = '\0';

	return (buf);
}
