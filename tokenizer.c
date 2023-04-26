#include "shell.h"

/**
 * tokenize - splits a string into an array of tokens
 * @line: the string to be tokenized
 * @delim: the delimiter used to split the string
 *
 * Return: an array of tokens, or NULL if an error occurs
 */
char **tokenize(char *line, const char *delim)
{
	char *buf, *token;
	char **tokens = NULL;
	size_t num_tokens = 0, max_tokens = 8;

	buf = strdup(line);
	if (!buf)
		return (NULL);

	tokens = malloc(max_tokens * sizeof(char *));
	if (!tokens)
	{
		free(buf);
		return (NULL);
	}

	token = strtok(buf, delim);
	while (token != NULL)
	{
		if (num_tokens == max_tokens - 1)
		{
			max_tokens *= 2;
			tokens = realloc(tokens, max_tokens * sizeof(char *));
			if (!tokens)
			{
				free(buf);
				return (NULL);
			}
		}
		tokens[num_tokens++] = strdup(token);
		token = strtok(NULL, delim);
	}

	tokens[num_tokens] = NULL;

	free(buf);
	return (tokens);
}
