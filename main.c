#include "main.h"
/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @argv: An array of strings representing the command-line arguments
 *
 * Return: 0 on successful termination
 */
int main(int ac, char **argv)
{
char *prompt = "(Eshell) $ ";
char *lineptr;
size_t n = 0;

(void)ac;
(void)argv;

printf("%s", prompt);
getline(&lineptr, &n, stdin);
printf("%s\n", lineptr);

free(lineptr);
return (0);
}

