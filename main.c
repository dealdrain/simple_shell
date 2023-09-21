#include "shell.h"

/**
 * main - main function and the entry point
 * @argc: count of arguments
 * @argv: argument vector
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
		count++;
		if (shell_mode == 1)
		{
			write(1, "$OurSimpleShell ", 2);
		}

		num = getline(&entry_buffer, &size, stdin);

		if (num == -1)
		{
			if (feof(stdin))
			{
				free(entry_buffer);
				print_string("\n");
				exit(error_code);
		}
			else
			{
				free(entry_buffer);
				exit(EXIT_FAILURE);
			}
		}
		if (num == 1 && entry_buffer[0] == '\n')
			continue;

		entry_buffer[num - 1] = '\0';

		check_comment(entry_buffer);
		error_code = process_input(entry_buffer, argv, error_code, count);
	}

	return (error_code);
}
