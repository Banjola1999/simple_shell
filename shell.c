#include "shell.h"

/**
 * shell_loop - Main loop for the shell program
 * Return: Always returns 0
 */
int shell_loop(void)
{
	char *line = NULL, **command = NULL, **paths = NULL, *pathcommand = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;

	while (1)
	{
	free(line);
	free_arr(command);
	free_arr(paths);
	free(pathcommand);
	prompt();
	linesize = getline(&line, &bufsize, stdin);
	if (linesize < 0)
		break;
	info.ln_count++;
	if (line[linesize - 1] == '\n')
		line[linesize - 1] = '\0';
	command = tokenize(line, " \t\r\n");
	if (!command || !*command || !**command)
		continue;
	if (checker(command, line))
		continue;
	paths = tokenize(env_path(), ":");
	pathcommand = path_test(paths, command[0]);
	if (!pathcommand)
		perror("shell");
	else
		exec(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	free_arr(command);
	free_arr(paths);
	free(pathcommand);
	return (0);
}
