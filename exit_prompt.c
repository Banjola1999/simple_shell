#include "shell.h"

/**
* exit_prompt - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_prompt(char **command, char *line)
{
	free_buf(command);
	free(line);
	exit(0);
}
