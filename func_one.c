#include "shell.h"

/**
 * process_input - takes user input, splits into tokens and
 * returns an array of strings
 * @argv: Command argument
 * @mode: checks for interative mode or not
 * Return: Array of strings
 */

char **process_input(char **argv, int *mode)
{
	char *user_input = NULL;
	char **token_arr = NULL;
	size_t buff_size = 0;
	ssize_t str_size;
	int x = 0;

	signal(SIGINT, handle_signal);
	str_size = getline(&user_input, &buff_size, stdin);
	if (str_size < 0)
	{
		free(user_input);
		if (*mode == 1)
			write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	while (user_input[x])
	{
		if (user_input[0] != '#' && user_input[x] ==
				'#' && user_input[x - 1] != ' ')
			break;

		if (user_input[x] == '#')
			user_input[x] = '\0';
		x++;
	}
	token_arr = splitter(user_input);

	if (token_arr == NULL)
	{
		free(user_input);
		free_array(token_arr);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	free(user_input);
	return (token_arr);
}

/**
 * tokenize - Tokenizes a string and returns
 * a dynamically allocated array of strings
 * @str: input entered by user
 * Return: Double pointer of the string
 */

char **tokenize(char *str)
{
	char **tokens_arr = NULL;
	int x = 0;
	char *token = NULL, *delim = " \n";

	tokens_arr = malloc(sizeof(char *) * 25);
	if (tokens_arr == NULL)
		return (NULL);

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens_arr[x] = token;
		token = strtok(NULL, delim);
		x++;
	}

	tokens_arr[x] = NULL;
	return (tokens_arr);
}

/**
 * _getpath - Retrieves and duplicates the path
 * Return: A strings of the PATH Variable
 */

char *_getpath(void)
{
	int x;
	char *duplicate = NULL;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (strncmp(environ[x], "PATH", 4) == 0)
			duplicate = strdup(environ[x]);
	}
	return (duplicate);
				}
