#include "shell.h"

/**
 *_signal- prompt signal
 *@index: signal index
 *Return: void
 */

void _signal(int index)
{
	(void)index;

	write(STDERR_FILENO, "\n$ ", 3);
}
