#include "shell.h"

/**
 * _free - frees an array of string buffers
 * @buf: pointer to the array of string buffers to be freed
 *
 * This function frees each individual string buffer within the array
 * pointed to by `buf`, and then frees the array itself. If `buf` is
 * NULL or points to NULL, this function does nothing.
 */
void _free(char **buf)
{
        int i;

        if (buf == NULL || *buf == NULL)
        {
                return;
        }

        for (i = 0; buf[i] != NULL; i++)
        {
                free(buf[i]);
                buf[i] = NULL;
        }
        free(buf);
}
