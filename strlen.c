#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string passed
 *
 * Return: returns length of string passed
 */
int _strlen(char *s)
{
int count = 0;
int i;

for (i = 0; s[i] != '\0'; i++)
{
count++;
}

return (count);
}
