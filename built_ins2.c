#include "shell.h"

/**
 * exit _shell- Exit the shell.
 * @args: Arguments.
 *
 * Return: Nothing.
 */

void exit_shell(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
	{
		exit_status = _atoi(args[1]);
	}
	free_tokens(args);
	free_last_input();
	exit(exit_status);
}

/**
 * display_help - displays help information for built-in commands
 */

void display_help(void)
{
	_print("\nShell Version 1.0.0\n\n");
	_print("Usage: ./hsh\n\n");
	_print("Shell built-in commands:\n\n");
	_print("help\t\tDisplay this help information\n\n");
	_print("cd [dir]\tChange the current working directory\n\n");
	_print("env\t\tDisplay the environment variables\n\n");
	_print("setenv\t\tSet an environment variable\n\n");
	_print("unsetenv\tUnset an environment variable\n\n");
	_print("exit\t\tExit the shell\n\n");
}

/**
 * set_environment_variable - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 *
 * Return: Nothing
 */

int set_environment_variable(char **args)
{
	char *variable_name, *variable_value;

	if (args[1] == NULL || args[2] == NULL)
	{
		print_error("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	variable_name = args[1];
	variable_value = args[2];

	if (setenv(variable_name, variable_value, 1) != 0)
	{
		print_error("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unset_environment_variable - Unset an environment variable
 * @args: Arguments (name of the environment variable)
 *
 * Return: Nothing
 */

int unset_environment_variable(char **args)
{
	char *variable_name;

	if (args[1] == NULL)
	{
		print_error("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	variable_name = args[1];

	if (unsetenv(variable_name) != 0)
	{
		print_error("unsetenv");
	}
	return (0);
}
