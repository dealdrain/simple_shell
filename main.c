#include "shell.h"

/**
 * main - main function and the entry point
 * @argc: count of arguments
 * @argv: argument vector
 * @environ: this is the environment variable
 * Return: error code
 */

int main(int argc, char **argv, char **environ)
{
	int shell_mode = 0;

	count = 1;
	(void)argc;

	if (isatty(0) == 1)
		shell_mode = 1;

	errno = 0;

	while (1)
	{
		if (shell_mode == 1)
		{
			write(1, "$OurSimpleShell ", 2);
		}

		handle_mode(argv, environ, &count, &mode);
		count++;
	}

	return (errno);
}
