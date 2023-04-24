#include "shell.h"

/**
 * _strdup - duplicates a string
 * @s: string to duplicate
 *
 * Return: pointer to newly allocated space in memory containing the duplicated
 * string, or NULL if memory allocation fails or s is NULL
 */
char *_strdup(char *s)
{
char *ptr
size_t len;

if (s == NULL)
return (NULL);

len = strlen(s);

ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
return (NULL);

strcpy(ptr, s);

return (ptr);
}
