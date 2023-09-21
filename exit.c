#include "shell.h"

/**
 * exit_func - this is the function that terminates current process
 * @argv: Argument vector
 * @environ: This is the environment variables
 * @token_arr: this is the array of user's token
 */

void exit_func(char **argv, char **environ, char **token_arr)
{
	int status_two;

	(void)environ;

	if (token_arr[1] && _substr(token_arr[1], "HBTN"))
	{
		cus_err_msg(2, 1, argv[0], token_arr[0], "Illegal number: -98");
		free_array(token_arr);
		errno = 2;
		exit(errno);
	}
	if (token_arr[1])
	{
		status_two = atoi(token_arr[1]);
		free_array(token_arr);
		errno = status_two;
		exit(errno);
	}
	if (errno != 0)
	{
		free_array(token_arr);
		exit(2);
	}
	free_array(token_arr);
	exit(errno);
}
