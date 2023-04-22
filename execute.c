#include "shell.h"

/**
 * exec - Executes commands entered by users.
 *
 * @cp: Command to execute.
 * @cmd: Vector array of pointers to commands.
 *
 * Return: void.
 */
void exec(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();

	if (child_pid < 0)
		perror(cp);
	
	if (child_pid == 0)
	{
		if (execve(cp, cmd, env) == -1)
		{
			perror(cp);
			free(cp);
			_free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
