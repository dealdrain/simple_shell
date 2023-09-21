#include "shell.h"

/**
 * check_builtins - Check built-in commands
 * @argv: Arguments
 * @environ: This is the environment variable
 * @token_arr: this splits the user's input
 * Return: 1 if a built-in command was executed, 0 otherwise
 */

int check_builtins(char **argv, char **environ, char **token_arr)
{
	int x = -1, y = 0;

	built_ins cd_s = {"cd", cd_func};
	built_ins exit_s = {"exit", exit_func};
	built_ins env_s = {"env", env_func};

	built_ins *builtin_ptr[3];

	builtin_ptr[0] = &cd_s;
	builtin_ptr[1] = &exit_s;
	builtin_ptr[2] = &env_s;

	while (y < 3)
	{
		if (_strcmp(token_arr[0], builtin_ptr[i]->cmd) == 0)
		{
			builtin_ptr[i]->func_cmd(argv, environ, token_arr);
			x = 1;
			break;
		}
		y++;
	}

	return (x);
}

/**
 * chng_dir - this function changes current directory
 * @argv: Argument vector
 * @environ: this is the environment variables
 * @token_arr: this is the array of user tokens
 */

void chng_dir(char **argv, char **environ, char **token_arr)
{
	char *dir = NULL;
	char *old = getenv("OLDPWD");
	size_t size = 0;

	void(environ);

	if (token_arr[1] != NULL)
	{
		if (token_arr[1][0] == '-')
		{
			chdir(old);
		}
		else if (chdir(token_arr[1]) == -1)
		{
			cus_err_msg(2, cmd_count, argv[0], "can't cd to", token_arr[1]);
		}
		return;
	}
	if (chdir(getcwd(dir, size)) == -1)
	{
		cus_err_msg(2, cmd_count, argv[0], "can't cd to", token_arr[2]);
	}
	free(dir);
}
