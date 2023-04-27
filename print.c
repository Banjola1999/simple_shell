#include "shell.h"

/**
* print - print string function
* @s: string
*
* Return: number of characters
*/
int print(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
