#include "shell.h"

/**
 * builtins - deals with built_in commands
 * @command: commands tokenized
 * @line: input command
 *
 * Return: 1 (Success)
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
