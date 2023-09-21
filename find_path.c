#include <stdlib.h>
#include "shell.h"

/**
 * get_path - this returns a pointer to the path variable
 * @environ: this is the nvironmental Variable
 * Return: the pointer to the paths
 */

char *get_path(char **environ)
{
	char *path = NULL;
	int x = 0;

	while (environ[x])
	{
		if (_substr(environ[x], "PATH") && environ[x][0] == 'P'
				&& environ[x][4] == '=')
		{
			path = environ[x];
			break;
		}
		x++;
	}
	if (path != NULL)
	{
		for (x = 0; x < 6; x++;)
			path++;
	}
	return (path);
}


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
i		token = strtok(NULL, ":");
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

/**
 * check_path - checks if string exists in the path
 * @cmd: this is the command to be searched
 * @path: this is the path variable
 * Return: Pointer to string if it exists or NULL if fail
 */

char *check_path(char *cmd, char *path)
{
	char *check = NULL;

	if (path != NULL)
		check = _substr(path, cmd);

	return (check);
}
