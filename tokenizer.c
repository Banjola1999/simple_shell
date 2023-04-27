#include "shell.h"

/**
 * count_tokens - counts the number of tokens in a string
 * @line: the string to count tokens from
 *
 * Return: the number of tokens
 */
int count_tokens(char *line)
{
char *delim = " :\t\r\n";
int tokensize = 1, flag = 0;

while (*line)
{
if (search(delim, *line) != NULL && flag == 0)
{
tokensize++;
flag = 1;
}
else if (search(delim, *line) == NULL && flag == 1)
flag = 0;
line++;
}

return (tokensize);
}

/**
* tokenizer - tokenizes a string into an array of tokens
* @line: the string to tokenize
*
* Return: an array of tokens
*/
char **tokenizer(char *line)
{
char *buf = NULL, *token = NULL, *delim = " :\t\r\n";
char **tokens = NULL;
size_t index = 0;

buf = duplicate(line);
if (!buf)
return (NULL);

tokens = malloc(sizeof(char *) * (count_tokens(line) + 1));
token = strtok(buf, delim);
while (token)
{
tokens[index] = duplicate(token);
if (tokens[index] == NULL)
{
free(tokens);
return (NULL);
}
token = strtok(NULL, delim);
index++;
}
tokens[index] = NULL;
free(buf);

return (tokens);
}
