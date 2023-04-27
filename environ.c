#include "shell.h"

/**
* _environ - prints the environment string to stdout
*
* Return: 0 (Success)
*/
void _environ(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{

	size_t len = string_length(env[i]);

	write(STDOUT_FILENO, env[i], len);
	write(STDOUT_FILENO, "\n", 1);
	i++;
	}
}
