#include "shell.h"

/**
 * _putchar - writes the _putchar to stdout
 * Return: (1) in success, otherwise -1
 */

int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _print - prints a string followed by a new line
 * @str: a pointer to a string to be printed
*/

void _print(char *str)
{
	size_t len;
	ssize_t num;

	len = _strlen(str);
	num = write(STDOUT_FILENO, str, len);
	if (num == -1)
		perror("write");
}

/**
 * print_prompt - Print shell prompt to stdin stream.
 *
 * Return: void.
 */

void print_prompt(void)
{
	_print(_PROMPT);
	fflush(stdout);
}

/**
 * _puterror - writes an error message to stderr
 * @err_msg: the error message to write
 */
void print_error(char *err_msg)
{
	size_t msg_len;
	ssize_t bytes_written;

	msg_len = _strlen(err_msg);

	for (size_t i = 0; i < msg_len; i++)
	{

		bytes_written = write(STDERR_FILENO, err_msg + i, 1);

		if (bytes_written == -1)
		{
			perror("write");
			break;
		}
	}
}
