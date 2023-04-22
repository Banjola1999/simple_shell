#include "shell.h"

/**
 * tokenize - Tokenize a string based on a delimiter
 * @line: The input string to tokenize
 * @delim: The delimiter to use for tokenization
 *
 * Return: An array of strings containing the tokens, or NULL on failure
 */
char **tokenize(char *line, const char *delim)
{
        char *buf, *token;
        char **tokens = NULL;
        size_t num_tokens = 0, max_tokens = 8;

        buf = strdup(line);
        if (!buf) {
                return (NULL);
        }

        tokens = malloc(max_tokens * sizeof(char *));
        if (!tokens) {
                free(buf);
                return (NULL);
        }

        token = strtok(buf, delim);
        while (token != NULL) {
                if (num_tokens == max_tokens - 1) {
                        max_tokens *= 2;
                        tokens = realloc(tokens, max_tokens * sizeof(char *));
                        if (!tokens) {
                                free(buf);
                                return (NULL);
                        }
                }
                tokens[num_tokens++] = strdup(token);
                token = strtok(NULL, delim);
        }

        tokens[num_tokens] = NULL;

        free(buf);
        return tokens;
}
