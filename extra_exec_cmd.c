#include "shell.h"

/**
 * extra_exec_cmd - This executes the command
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * @get_full_path: this get the full command
 * Return: Void
 */

int extra_exec_cmd(char **args, char **argv, char *get_full_path)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(get_full_path);
		exit(-1);
	}
	else if (child_pid == 0)
	{
		execve(get_full_path, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);

		free(get_full_path);
		free(args);
	}
	return (status);
}
