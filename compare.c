#include "shell.h"

/**
* compare - compares two strings
* @s1: string 1
* @s2: string 2
*
* Return: returns difference s1 and s2
*/
int compare(char *s1, char *s2)
{
	int i = 0, diff;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	diff = (*(s1 + i) - *(s2 + i));

	return (diff);
}
