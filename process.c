#include "shell.h"

/**
 * process_input- processing inp
 * @entry_buffer: input buffer
 * @argv: arg vector
 * @error_code: error
 * @count: counts the number of commands
 * Return: error code
 */

int process_input(char *entry_buffer, char **argv, int error_code, int count)
{
	char *get_full_path = NULL, char_cmd, **args = NULL;
	int status = 0;

	args = tokenize(entry_buffer);
	if (args[0] == NULL)
	{
		free(args);
		return (error_code);
	}

	if (access(args[0], X_OK) == -1)
	{
		status = check_builtins(args, argv[0], entry_buffer);

		if (status == 1)
		{
			free(args);
			return (error_code);
		}

		get_full_path = find_path(_getpath(), args[0]);

		if (get_full_path == NULL)
		{
			char_cmd = (count + '0');
			custom_error(argv[0], char_cmd, args[0]);
			free(args);
			error_code = 127;

			return (error_code);
		}
	}

	exec_cmd(args, argv);
	return (error_code);
}
