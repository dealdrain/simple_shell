#include "shell.h"

/**
 * process_path - this process path when command name is passed
 * @argv: this is the argument
 * @environ: this is the environment variables
 * @token_arr: array of token
 * @cmd_count: count of command
 * Return: 0 if success or -1 if fail
 */

int process_path(char **argv, char **environ, char **token_arr, int *cmd_count)
{
	char **paths_arr = splitter(get_path(environ)), *full_path;
	int x = 0, len, val, status = -1;
	pid_t child_pid;

	(void)cmd_count;
	if (paths_arr == NULL)
		return (-1);

	while (paths_arr[x])
	{
		len = _strlen(paths_arr[x]) + _strlen(token_arr[0]) + 2;
		full_path = malloc(len);
		_strcpy(full_path, paths_arr[x]);
		_strcat(full_path, "/");
		_strcat(full_path, token_arr[0]);
		if (access(full_path, F_OK) == -1)
		{
			free(full_path), x++, errno = 127;
			continue;
		}
		else
		{
			status = 1, child_pid = fork();
			if (child_pid == -1)
				return (-1);
			else if (child_pid == 0)
			{
				val = execve(full_path, token_arr, environ);
				if (val == -1)
					perror(argv[0]), exit(EXIT_FAILURE);
			}
			else
				wait(&status), free(full_path), errno = status;
			break;
		}
	}
	free_array(paths_arr);
	return (status);
}
