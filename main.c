#include "shell.h"

/**
 * main - Entry point for the shell program
 * @ac: The number of arguments passed to the program
 * @av: The array of arguments passed to the program
 * @envp: The array of environment variables
 *
 * Return: Always returns 0
 */
int main(int ac, char **av, char *envp[])
{
	(void)envp, (void)av;

	if (ac < 1)
	return (-1);

	shell_loop();

	return (0);
}
