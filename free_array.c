#include "shell.h"

/**
 * free_array - this frees an array of tokens
 * @arr_tokens: this is the pointer to array of tokens
 * Return: Always Void;
 */

void free_array(char **arr_tokens)
{
	int x = 0;

	while (arr_tokens[x] != NULL)
	{
		free(arr_tokens[x]);
		x++;
	}

	free(arr_tokens);
}
