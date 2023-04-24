#include "shell.h"

/**
 * _exit_ - handles the exit command
 * @command: tokenized command
 * @line: input read from stdin
 *
 * This function frees the memory allocated for
 * the input line and tokenized command,
 * then terminates the program with a successful exit status.
 *
 * Return: No return value.
 */
void _exit_(char **command, char *line)
{
	free(line);
	_free(command);
	exit(0);
}
