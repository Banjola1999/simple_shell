#include "shell.h"

/**
 * prompt - Prints $ to let user know the program is ready to take their input.
 * If the shell is in interactive mode, prints the prompt.
 *
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
		flags.interactive = 1;

	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
