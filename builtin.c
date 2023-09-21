#include "shell.h"

/**
 * check_builtins - Check built-in commands
 * @argv: Arguments
 * @environ: This is the environment variable
 * @token_arr: this splits the user's input
 * Return: 1 if a built-in command was executed, 0 otherwise
 */

int check_builtins(char **argv, char **environ, char *entry_buffer)
{
	int x = 0, y = 0;

	(void)unused;
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(entry_buffer);
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[y] != NULL)
		{
			write(1, environ[y], strlen(environ[y]));
			write(1, "\n", 1);
			y++;
		}
		free(args);
		x = 1;
	}
	return (x);
}
