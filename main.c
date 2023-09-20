#include "shell.h"

/**
 * main- main function
 * @argc: count of args
 * @argv: arg vec
 * Return: error code
 */

int main(int argc, char **argv)
{
	int shell_mode = isatty(0);
	char *entry_buffer = NULL;
	char *prompt_message = "OurSimpleShell>$ ";
	size_t size = 0;
	ssize_t num = 0;
	int error_code = 0, counter = 0;

	(void)argc;
	while (1)
	{
		counter++;
		if (shell_mode == 1)
			print_string(prompt_message);

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
		error_code = process_input(entry_buffer, argv, error_code, counter);
	}

	return (error_code);
}
