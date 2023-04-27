#include "shell.h"

/**
 *_signal- it keeps track is interactive mode
 *@index: signal index
 *Return: void
 */

void _signal(int index)
{
	(void)index;

	write(STDERR_FILENO, "\n:) $ ", 3);
}
