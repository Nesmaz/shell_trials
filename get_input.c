#include "shell.h"
static char *recent_input;

/**
 * get_input - reads user's input
 * Return: pointer to the buffer that contains the input
*/

char *get_input(void)
{
	char *input_buf = NULL;
	size_t buf_size = 0;
	ssize_t count;

	do {
		print_prompt();

		count = getline(&input_buf, &buf_size, stdin);

		if (count == -1)
		{
			free(input_buf);
			_print("\n");
			return (NULL);
		}
		input_buf[count - 1] = '\0';
	} while (input_buf[0] == '\0' || isspace(input_buf[0]));

	recent_input = input_buf;
	return (input_buf);
}

/**
 * free_recent_input - frees the memory allocated for recent input
*/

void free_recent_input(void)
{
	free(recent_input);
	recent_input = NULL;
}
