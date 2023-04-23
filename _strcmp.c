#include "shell.h"

/**
 * _strncmp - compares two strings up to a given number of bytes
 * @s1: the first string to compare
 * @s2: the second string to compare
 * @n: the maximum number of bytes to compare
 *
 * Return: 0 if the two strings are equal up to n bytes, a negative number if
 * s1 is less than s2, or a positive number if s1 is greater than s2
 */
int _strncmp(char *s1, char *s2, int n)
{
while (n-- > 0 && *s1 && *s2)
{
if (*s1++ != *s2++)
return (*--s1 - *--s2);
}
return (0);
}
