#include "shell.h"

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
