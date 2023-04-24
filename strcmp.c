#include "shell.h"

/**
 * _strcmp - Compares two strings recursively.
 *
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: The difference between the first non-matching characters
 *         in the two strings. If the strings are identical, returns 0.
 */
int _strcmp(char *s1, char *s2)
{
/* Base case: both strings are empty */
if (*s1 == '\0' && *s2 == '\0')
{
return (0);
}
/* If the characters match, recurse on the next characters */
else if (*s1 == *s2)
{
return _strcmp(s1 + 1, s2 + 1);
}
/* The characters don't match, so return the difference between them */
else
{
return (*s1 - *s2);
}
}
