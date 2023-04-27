#include "shell.h"

/**
* string_length - returns the length of a string
* @s: string passed
*
* Return: length of string
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
