#include "shell.h"

/**
* string_bytes - compares two strings
* @s1: string one
* @s2: string two
* @n: number of bytes
*
* Return: difference between strings
*/
int string_bytes(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
