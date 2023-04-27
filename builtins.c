#include "shell.h"

/**
 * builtins - handles execution of builtin functions
 * @command: tokenized commands
 * @line: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */
int builtins(char **command, char *line)
{
struct builtin builtin = {"env", "exit"};

switch (compare(*command, builtin.env))
{
case 0:
_environ();
return (1);
case 1:
break;
default:
switch (compare(*command, builtin.exit))
{
case 0:
exit_prompt(command, line);
return (1);
case 1:
break;
default:
break;
}
}

return (0);
}
