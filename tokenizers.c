#include "shell.h"
/**
 * tokenize - splits a string into tokens using a delimiter
 * @str: the string to be tokenized
 * @delim: the delimiter used to split the string
 * Return: array of pointers to the tokens or NULL
*/
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **tokens = NULL;
	int num_tokens = 0;

	token = strtok(str, delim);
	while (token)
	{
		tokens = realloc(tokens, sizeof(char *) * (num_tokens + 1));
		if (tokens == NULL)
		return (NULL);

		tokens[num_tokens] = malloc(_strlen(token) + 1);
		if (!(tokens[num_tokens]))
			return (NULL);

		_strcpy(tokens[num_tokens], token);
		token = strtok(NULL, delim);
		num_tokens++;
	}

	tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
	if (!tokens)
		return (NULL);

	tokens[num_tokens] = NULL;
	return (tokens);
}


/**
 * tokenize_input - splits a user input string into tokens using tokenize()
 * @str: the user input string to be tokenized
 * Return: an array of pointers to the tokens, or NULL
 */
char **tokenize_input(char *str)
{
	char **tokens = NULL;
	char *cpy = NULL;

	cpy = _strdup(str);
	if (!cpy)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(cpy, " \t\r\n\a");
	free(cpy);

	return tokens;
}

/**
 * free_tokens - frees the memory allocated by tokenize
 * @ptr: pointer to the allocated memory
*/
void free_tokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}
~ 
