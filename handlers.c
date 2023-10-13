#include "shell.h"

/**
 * register_signal_handlers - a function to call the 3 handlers functions
 */

void register_signal_handlers()
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);
}

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
	print_error("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * _sigstp - handles SIGTSTP signal
 * @signal: Signal number
 */
void _sigstp(int signal)
{
	(void) signal;
	_print("\n");
	print_prompt();
}
