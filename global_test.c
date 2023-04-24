#include "shell.h"

/**
 * env_path - finds the path from the global environment
 * Return: NULL if path is not found or path if path is found.
 */
char *env_path(void)
{
char **env = environ;
char *path = NULL;

while (*env)
{
if (_strncmp(*env, "PATH=", 5) == 0)
{
path = *env + 5;
if (*path != '\0')
{
return (path);
}
}
env++;
}
return (NULL);
}
