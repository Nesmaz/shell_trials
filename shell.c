#include "shell.h"

/**
 * main - entry point
 * Return: EXIT_SUCCESS
*/

int main(void)
{
	char *input;
	char **tokenized_input;
	int status;

	register_signal_handlers();

	do {
		input = get_input();
		if (!input || !*input)
			break;

		tokenized_input = tokenize_input(input);
		if (!tokenized_input || !*tokenized_input)
		{
			free(input);
			free_tokens(tokenized_input);
			continue;
		}
		status = execute(tokenized_input);
		free(input);
		free_tokens(tokenized_input);
		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}
