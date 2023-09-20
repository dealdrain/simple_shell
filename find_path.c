#include "shell.h"

/**
 * find_path - find the full valid path
 * @paths: A string of multiple directories in the path
 * @cmd: the command
 * Return: A Pointer to full string or NULL
 */
char *find_path(char *paths, char *cmd)
{
	char **path_tokens = NULL, *token = NULL, *temp = NULL, *fullpath = NULL;
	int x = 0;
	size_t len = 0;

	if (paths == NULL)
		return (NULL);
	temp = strtok(paths, "=");
	temp = strtok(NULL, "=");
	path_tokens = malloc(sizeof(char *) * 30);
	if (path_tokens == NULL)
	{
		free(paths);
		return (NULL);
	}
	token = strtok(temp, ":");
	while (token != NULL)
	{
		path_tokens[x] = token;
		token = strtok(NULL, ":");
		x++;
	}
	path_tokens[x] = NULL;
	x = 0;
	while (path_tokens[x] != NULL)
	{
		len = strlen(path_tokens[x]) + strlen(cmd) + 2;
		fullpath = malloc(len);
		strcpy(fullpath, path_tokens[x]);
		strcat(fullpath, "/");
		strcat(fullpath, cmd);
		if (access(fullpath, X_OK) == 0)
		{
			free(path_tokens);
			free(paths);
			return (fullpath);
		}
		free(fullpath);
		fullpath = NULL;
		x++;
	}
	free(path_tokens);
	free(paths);
	return (NULL);
}
