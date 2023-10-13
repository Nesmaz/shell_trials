#include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */

int check_for_builtins(char **args)
{
	if (!args[0])
		return (0);

	BuiltInCommand builtins[] = {
		{"exit", exit_shell}, {"env", display_environment},
		{"setenv", set_environment_variable}, {"unsetenv", unset_environment_variable},
		{"help", display_help}, {"cd", change_directory},
		{"clear", clear_screen}, {NULL, NULL}
	};

	for (int i = 0; builtins[i].name != NULL; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].function(args);
			return (1);
		}
	}
	return (0);
}
