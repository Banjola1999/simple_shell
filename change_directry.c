#include "shell.h"

/**
 * get_directory - get the directory to change to
 *
 * @args: array of arguments passed to the cd command
 *
 * Return: a pointer to the directory string, or NULL if an error occurred
 */
char *get_directory(char **args)
{
	char *dir;

	if (args[1] == NULL)
	dir = getenv("HOME");
	else if (strcmp(args[1], "-") == 0)
	dir = getenv("OLDPWD");
	else
	dir = args[1];

	return (dir);
}

/**
 * cd_command - change the current directory of the process
 *
 * @args: array of arguments passed to the cd command
 *
 * Return: 0 if successful, 1 if an error occurred
 */
int cd_command(char **args)
{
	char *dir = get_directory(args);
	char *new_cwd = getcwd(NULL, 0);
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
	perror("getcwd() error");
	return (1);
	}

	if (chdir(dir) != 0)
	{
	perror("chdir() error");
	free(cwd);
	return (1);
	}

	if (new_cwd == NULL)
	{
	perror("getcwd() error");
	return (1);
	}

	if (setenv("OLDPWD", cwd, 1) != 0)
	{
	perror("setenv() error");
	return (1);
	}

	if (setenv("PWD", new_cwd, 1) != 0)
	{
	perror("setenv() error");
	return (1);
	}

	free(cwd);
	free(new_cwd);
	return (0);
}
