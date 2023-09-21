#include "shell.h"

/**
 * handle_path - finds other path when tests fails
 * @token_arr: this is the array of user tokens
 * @env: this is the nvironment variables
 * @argv: program name
 * @mode: check if interactive or not
 * Return: Void
 */

void handle_path(char **token_arr, char **environ, char **argv, int mode)
{
	pid_t child_pid;
	int val;

	(void)mode;
	child_pid = fork();

	if (child_pid == -1)
		free_array(token_arr), perror(argv[0]), exit(EXIT_FAILURE);
	else if (child_pid == 0)
	{
		val = execve(token_arr[0], token_arr, environ);
		if (val == -1)
			free_array(token_arr), perror(argv[0]), exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status), free_array(token_arr);
		errno = status;
	}
}
