#include "shell.h"
/**
 * handle_up_arrow - Handles the signal for the up arrow key being pressed.
 * Saves the previous command in the `previous_command` global variable.
 *
 * @sig: The signal received.
 */
void handle_up_arrow(int sig)
{
int i = 0;
char c;
char buf[MAX_CMD_LENGTH] = {0};

if (sig == SIGINT)
{
struct termios old, new;
tcgetattr(STDIN_FILENO, &old);
new = old;
new.c_lflag &= ~(ICANON | ECHO);
tcsetattr(STDIN_FILENO, TCSANOW, &new);


while ((c = getchar()) != '\n' && c != EOF && i < MAX_CMD_LENGTH - 1)
{
if (c == 127 || c == '\b')
{
if (i > 0)
{
buf[--i] = '\0';
printf("\b \b");
}
}
else
{
buf[i++] = c;
putchar(c);
}
}

free(previous_command);
previous_command = strdup(buf);

tcsetattr(STDIN_FILENO, TCSANOW, &old);
}
}
