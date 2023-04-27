#include "shell.h"

/**
* string_bytes - compares two strings
* @s1: string one
* @s2: string two
* @num: number of bytes
*
* Return: difference between strings
*/
int string_bytes(char *s1, char *s2, int num)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < num; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
