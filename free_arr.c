#include "shell.h"
/**
 * free_arr - frees a NULL-terminated array of strings
 * @arr: the array to free
 */
void free_arr(char **arr)
{
int i;
if (!arr)
return;

for (i = 0; arr[i]; i++)
{
free(arr[i]);
}

free(arr);
}
