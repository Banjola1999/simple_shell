#ifndef _MAIN_H_
#define _MAIN_H_

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Structures */
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for storing command arguments
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

/* Function Prototypes */
int execute(char **args, char *input);
char **tokenize_input(char *input);
int _strlen(char *str);
char *_strdup(char *str);
int built_in(char **args);
void free_list(list_t *head);
void sig_handler(int sig);

#endif /* _MAIN_H_ */
