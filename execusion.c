#include "shell.h"

/**
 * execute_command - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */

int execute_command(char **argv)
{
	pid_t id;
	int exit_status = 0;
	char *command_path, *_env[2];

	if (argv == NULL || *argv == NULL)
		return (status);
	if (check_for_builtins(argv))
		return (status);

	id = fork();
	if (id < 0)
	{
		print_error("fork");
		return (1);
	}
	if (id == -1)
	{
		perror(argv[0]), free_tokens(argv), free_last_input();
	}
	if (id == 0)
	{
		_env[0] = get_path(), _env[1] = NULL, command_path = NULL;
		if (argv[0][0] != '/')
			command_path = find_in_path(argv[0]);
		if (command_path == NULL)
			command_path = argv[0];
		if (execve(command_path, argv, _env) == -1)
		{
			perror(argv[0]), free_tokens(argv), free_last_input(), exit(EXIT_FAILURE);
		}
	}
	else
	{
		while (waitpid(id, &status, WUNTRACED) > 0)
		{
			if (WIFEXITED(status) || WIFSIGNALED(status))
				break;
		}
	}
	return (status);
}
