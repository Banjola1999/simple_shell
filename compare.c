#include "shell.h"

/**
* compare - compares two strings
* @str1: string one
* @str2: string two
*
* Return: returns difference s1 and s2
*/
int compare(char *str1, char *str2)
{
	int i = 0, diff;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;

	diff = (*(str1 + i) - *(str2 + i));

	return (diff);
}
