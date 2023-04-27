#include "shell.h"

/**
* duplicate - dupicates string
* @str: string
*
* Return: pointer to string
*/
char *duplicate(char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
		return (NULL);

	len = string_length(str);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		ptr[i] = str[0];

	ptr[i++] = '\0';
	return (ptr);
}
