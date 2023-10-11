#include "shell.h"

/**
 * _sigint - handles SIGINT signal
 * @signal: Signal number
*/

void _sigint(int signal)
{
 	(void) signal;
	_putchar('\n');
	print_prompt();
}

/**
 * _sigquit - handles SIGQUIT signal
 * @signal: Signal number
*/

void _sigquit(int signal)
{
	(void) signal;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * _sigstp - handles SIGTSTP signal
 * @signal: Signal number
*/
void _sigstp(int signal)
{
	(void) signal;
	_puts("\n");
	print_prompt();
}
