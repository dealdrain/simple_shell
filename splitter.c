#include "shell.h"

/**
 * splitter - Splits the user input into tokens
 * @user_input: delimiter is " \n\t\r"
 * Return: array of strings if success or NULL on fail
 */

char **splitter(char *user_input)
{
	char **token_arr = NULL;
	char *tem_path = _strdup(user_input), *tem_tok;
	char *DELIM = " \"\n\t\r";
	int token_count = 0, x = 0;

	if (tem_path != NULL)
	{
		tem_path = strtok(tem_path, DELIM);
		while (tem_tok != NULL)
			token_count++, tem_tok = strtok(NULL, DELIM);
	}
	token_count++;
	token_arr = malloc(sizeof(char *) * token_count);
	if (token_arr == NULL)
	{
		perror("Error allocating memory for tokens.");
		free(tem_path);
		free(token_arr);
		exit(EXIT_FAILURE);
	}

	free(tem_path);
	tem_path = _strdup(user_input);
	tem_tok = strtok(tem_path, DELIM);
	token_arr[x] = _strdup(tem_tok);

	while (tem_tok != NULL)
	{
		x++;
		tem_tok = strtok(NULL, DELIM);
		if (tem_tok != NULL)
			token_arr[x] = _strdup(tem_tok);
	}
	token_arr[x] = NULL;
	free(tem_path);
	return (token_arr);
}
