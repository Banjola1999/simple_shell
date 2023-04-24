#include "shell.h"

/**
* print_env - prints the environment string to stdout
*
* Return: 0
*/
void print_env(void)
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
