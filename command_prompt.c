#include "shell.h"

/**
* user - prints $ that indacates that shell has ran successfully
* Return: void
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
