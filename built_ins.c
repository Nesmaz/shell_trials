#include "shell.h"

/**
 * change_directory - changes the current working directory of the shell
 * @args: array of arguments
 */

void change_directory(char **args)
{
	char *new_directory = args[1];
	int change_status;

	if (new_directory == NULL)
	{
		new_directory = _getenv("HOME");
		if (new_directory == NULL)
		{
			_print("cd: No HOME directory found\n");
			return;
		}
	}

	change_status = chdir(new_directory);
	if (change_status == -1)
	{
		perror("cd");
	}
}

/**
 * clear_screen - clears the terminal screen.
 * @args: an array of arguments
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
 */

int clear_screen(char **args)
{
	(void)args;
	_print("\033[2J\033[H");
	return (1);
}

/**
 * display_environment - Prints all the environment variables.
 *
 * Return: void.
 */

int display_environment(void)
{
	int index;

	for (index = 0; environ[index]; index++)
	{
		_print(environ[index]);
		_putchar('\n');
	}
	return (0);
}
