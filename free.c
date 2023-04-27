#include "shell.h"

/**
* free_buf - frees buffers
* @buf: buffer to be freed
*
* Return: void
*/
void free_buf(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
