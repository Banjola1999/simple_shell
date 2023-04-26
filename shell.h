#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

#define MAX_CMD_LENGTH 1024

/* function to recall the previous command*/
extern char *previous_command;
void handle_up_arrow(int sig);

/**
 * struct builtin - contains information about built-in commands
 * @env: pointer to the environment command
 * @exit: pointer to the exit command
 *
 * Description: This struct contains information about built-in commands
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/* Function Prototypes */
void prompt(void);


/**
 * struct info - contains information about program execution
 * @final_exit: integer value of program exit status
 * @ln_count: integer value of line count
 *
 * Description: This struct contains information about program execution
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
 * struct flags - contains flags for the program
 * @interactive: boolean value for interactive mode
 *
 * Description: This struct contains flags for the program
 */
struct flags
{
	bool interactive;
} flags;

/* Declare external environment variable and signal handler function */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* Function to prompt the user for input */
void prompt(void);

/*free dynamically allocated array */
void free_arr(char **arr);

char *prompt_and_read_input(void);
void execute_command(char *command);
int shell_loop(void);

/* Function to exit the shell program */
void _exit_(char **command, char *line);

/* Function to print environment variables */
void print_env(void);

/* Function to execute a command */
void exec(char *command, char **arguments);

/* Function to free allocated memory */
void _free(char **buf);

/* Function to handle builtin commands */
int builtins(char **cmd, char *line);

/* Function to check for special characters in a command */
int checker(char **cmd, char *buf);

/* Function to compare two strings */
int _strcmp(char *s1, char *s2);

/* Function to calculate the length of a string */
int _strlen(char *s);

/* Function to compare two strings up to a certain length */
int _strncmp(char *s1, char *s2, int n);

/* Function to duplicate a string */
char *_strdup(char *s);

/* Function to find a character in a string */
char *_strchr(char *s, char c);

/* Function to find the path of a command */
char *env_path(void);

/* Function to tokenize a command line into separate arguments */
char **tokenize(char *line, const char *delim);

/* Function to test a path for a command */
char *path_test(char **path, char *command);

/* Function to add a command to a path */
char *add_path(char *path, char *command);

#endif
