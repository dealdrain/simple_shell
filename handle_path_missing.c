#include "shell.h"

/**
 * handle_path_missing - checks the case of check 27 types
 * @in_path: this checks if the command is in the path
 * @token_arr: this is an array of user tokens
 * @environ: this is environment variables
 * @mode: Check if interactive or not
 * @cmd_count: Count of commands
 * @argv: program name
 * Return: Void
 */

int handle_path_missing(char *in_path, char **token_arr,
		char **environ, int *mode, int *cmd_count, char **argv)
{
	in_path = check_path(token_arr[0], get_path(environ));
	if (token_arr[0][0] != '/' && token_arr[0][0] != '.' &&
			token_arr[1] == NULL &&
			access(token_arr[0], F_OK) != -1 && in_path == NULL)
	{
		cus_err_msg(2, *cmd_count, argv[0], token_arr[0], "not found");
		free_array(token_arr);
		if (*mode != 1)
			exit(127);
		errno = 127;
		return (1);
	}
	else
		return (2);
}
