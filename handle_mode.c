#include "shell.h"

/**
 * handle_mode - checks for interactive mode
 * @argv: Argument vector
 * @environ: this is the environment variable
 * @cmd_count: count of commands
 * @mode: checks if mode is interactive or not
 * Return: Void
 */

void handle_mode(char **argv, char **environ, int *cmd_count, int *mode)
{
	char **token_arr = process_input(argv, mode), *in_path = NULL;

	if (token_arr[0] == NULL || token_arr == NULL)
	{
		free(token_arr[0]), free_array(token_arr);
		return;
	}
	if (check_builtins(argv, environ, token_arr) == 1)
	{
		free_array(token_arr);
		return;
	}
	if (handle_path_missing(in_path, token_arr, environ,
				mode, cmd_count, argv) == 1)
		return;
	if (access(token_arr[0], F_OK) == -1)
	{
		if (process_path(argv, environ, token_arr, cmd_count) == -1)
		{
			free_array(token_arr);
			return;
		}
		if (handle_path_missing(in_path, token_arr, environ,
					mode, cmd_count, argv) == 1)
			return;
		if (access(token_arr[0], F_OK) == -1)
		{
			if (process_path(argv, environ, token_arr, cmd_count) == -1)
			{
				cus_err_msg(2, *cmd_count, argv[0], token_arr[0], "not found");
				free_array(token_arr);
				if (*mode != 1)
					exit(127);

				errno = 127;
				return;
			}
			free_array(token_arr);
			return;
		}
