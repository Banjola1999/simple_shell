#include "shell.h"

/**
* search - searches a character in a string
* @s: string
* @c: character location
*
* Return: returns pointer to first character
*/
char *search(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
