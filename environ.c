#include "shell.h"

/**
 * environ_func - prints the environment
 * @argv: Argument vector
 * @env: this is the environment variables
 * @token_arr: this is the array of user tokens
 */

void environ_func(char **argv, char **environ, char **token_arr)
{
	int x = 0, y = 0;

	(void)argv;
	(void)token_arr;

	while (environ[x])
	{
		while (environ[x][y])
		{
			write(1, &environ[x][y], 1);
			y++;
		}
		y = 0;
		x++;
		write(1, "\n", 1);
	}
}
