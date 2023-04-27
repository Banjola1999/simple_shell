#include "shell.h"

/**
* string_length - returns the length of a string
* @s: string passed
*
* Return: returns length of string passed
*/
int string_length(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
