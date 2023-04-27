#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

/* Structs */

/**
 * struct builtin - holds built-in command strings
 * @env: string for the "env" command
 * @exit: string for the "exit" command
 */
struct builtin
{
	char *env;
	char *exit;
};

/**
 * struct info - holds information about the shell
 * @_exit: the exit status of the last command executed
 * @_count: the number of commands executed in the shell
 */
struct info
{
	int _exit;
	int _count;
};

/**
 * struct flags - holds boolean flags for the shell
 * @run: indicates if the shell is running in interactive mode
 */
struct flags
{
	bool run;
};

/* Function prototypes */

int _putchar(char c);
int checker(char **cmd, char *buf);
void user(void);
void _signal(int m);
char **tokenizer(char *line);
char *path_check(char **path, char *command);
char *_path_(char *path, char *command);
int builtins(char **command, char *line);
void exit_prompt(char **command, char *line);
char *get_directory(char **args);
int cd_command(char **args);
void _environ(void);
int compare(char *s1, char *s2);
int string_length(char *s);
int string_bytes(char *str1, char *str2, int num);
char *duplicate(char *str);
char *search(char *s, char c);
void exec(char *cp, char **cmd);
char *Path(void);
void free_buf(char **buf);

/* environment variables */
extern char **environ;
struct builtin builtin;
struct info info;
struct flags flags;

#endif /* SHELL_H */
