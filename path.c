#include "shell.h"

/**
 * Path - finds the PATH environment variable in the global environment
 *
 * Return: a pointer to the path string if found, NULL otherwise
 */
char *Path(void)
{
char **env = environ;
char *path = NULL;
int i;

for (i = 0; env[i] != NULL; i++)
{
if (string_bytes(env[i], "PATH=", 5) == 0)
{
path = env[i] + 5;
return (path);
}
}

return (NULL);
}
