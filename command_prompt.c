#include "shell.h"

/**
* user - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
	{
		flags.run = 1;
	}
	if (flags.run)
	{
		write(STDERR_FILENO, "$ ", 2);
	}
}
