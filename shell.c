#include "shell.h"

/**
 * main - Entry point for the shell program
 * @ac: The number of arguments passed to the program
 * @av: The array of arguments passed to the program
 * @envp: The array of environment variables
 *
 * Return: Always returns 0
 */
int main(int ac, char **av, char *envp[])
{
char *line = NULL, *pathcommand = NULL, *path = NULL;
size_t bufsize = 0;
ssize_t linesize = 0;
char **command = NULL, **paths = NULL;

(void)envp, (void)av;

if (ac < 1)
return (-1);

while (1)
{
_free(command);
_free(paths);
free(pathcommand);
prompt();
linesize = getline(&line, &bufsize, stdin);

if (linesize < 0)
break;

info.ln_count++;

if (line[linesize - 1] == '\n')
line[linesize - 1] = '\0';

command = tokenize(line, " \t\r\n");

if (command == NULL || *command == NULL || **command == '\0')
continue;
if (checker(command, line))
continue;
path = env_path();
paths = tokenize(path, ":");
pathcommand = path_test(paths, command[0]);

if (!pathcommand)
perror(av[0]);
else
exec(pathcommand, command);
}

if (linesize < 0 && flags.interactive)
write(STDERR_FILENO, "\n", 1);

free(line);
free_arr(command);
free_arr(paths);

return (0);
}
