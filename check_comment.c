#include "shell.h"

/**
 * check_comment - Checks if the string is a comment
 * @buf: The string to check and fix a null byte at point of #
 * Return: Void
 */

void check_comment(char *buf)
{
	int i = 0;

	while (buf[i])
	{
		if (i > 0 && buf[i] == '#' && buf[i - 1] != ' ')
			break;

		if (buf[i] == '#')
		{
			buf[i] = '\0';
			break;
		}

		i++;
	}
}
