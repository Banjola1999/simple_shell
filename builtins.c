#include "shell.h"

/**
 * builtins - executes a built-in command
 * @cmd: the command and its arguments
 * @line: the input read from stdin
 * 
 * Return: 1 if the command was a built-in, 0 otherwise
 */
int builtins(char **cmd, char *line)
{
        char *builtins[] = {"env", "exit"};
        int num_builtins = sizeof(builtins) / sizeof(char *);
        int i;

        for (i = 0; i < num_builtins; i++)
        {
                if (_strcmp(*cmd, builtins[i]) == 0)
                {
                        if (i == 0)
                        {
                                print_env();
                                return (1);
                        }
                        else if (i == 1)
                        {
                                _exit_(cmd, line);
                                return (1);
                        }
                }
        }
        return (0);
}
