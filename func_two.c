#include "shell.h"

/**
 * path_split - this splits the variable path
 * @path_dir: this is a string of directories of delimiter :
 * Return: an array of strings if success or NULL if fail
 */

char **path_split(char *path_dir)
{
	char **token_arr = NULL;
	int num = 0, x = 0;
	char *tem_path = _strdup(path_dir), *tem_tok;

	if (path_dir == NULL)
		return (NULL);

	if (tem_path != NULL)
	{
		tem_tok = strtok(tem_path, ":");
		while (tem_tok != NULL)
			num++, tem_tok = strtok(NULL, ":");
	}
	num++;
	token_arr = malloc(sizeof(char *) * num);
	if (token_arr == NULL)
	{
		perror("Error allocating memory for tokens.");
		free(tem_path);
		return (NULL);
	}
	free(tem_path);
	tem_path = _strdup(path_dir);
	tem_tok = strtok(tem_path, ":");
	token_arr[x] = _strdup(tem_tok);

	while (tem_tok != NULL)
		x++, tem_tok = strtok(NULL, ":"),
			token_arr[x] = _strdup(tem_tok);

	token_arr[x] = NULL;
	free(tem_path);
	return (token_arr);
}
