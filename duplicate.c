#include "shell.h"

/**
* duplicate - dupicates string
* @s: string
*
* Return: pointer to string
*/
char *duplicate(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = string_length(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}
