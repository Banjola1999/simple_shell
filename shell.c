#include "shell.h"

/**
* main - calls all the functions
* @ac: count
* @av: vector
* @envp: environment
*
* Return: 0 (Success)
*/
int main(int ac, char **av, char *envp[])
{
char *line = NULL, *pathcommand = NULL, *path = NULL;
size_t bufsize = 0;
ssize_t linesize = 0;
char **command = NULL, **paths = NULL;
/*char *args[] = {"cd", "/path/to/dir", NULL};*/
(void)av, (void)envp;

if (ac < 1)
return (-1);
signal(SIGINT, _signal);
while (true)
{
free_buf(command);
free_buf(paths);
free(pathcommand);
user();
linesize = getline(&line, &bufsize, stdin);
if (linesize < 0)
break;
info._count++;
if (line[linesize - 1] == '\n')
line[linesize - 1] = '\0';
command = tokenizer(line);
if (command == NULL || *command == NULL || **command == '\0')
continue;
if (checker(command, line))
continue;
path = Path();
paths = tokenizer(path);
pathcommand = path_check(paths, command[0]);
if (!pathcommand)
perror(av[0]);
else
exec(pathcommand, command);
}
if (linesize < 0 && flags.run)
write(STDERR_FILENO, "\n", 1);
free(line);
return (0);
}
