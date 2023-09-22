#include "shell.h"

/**
 * cus_err_msg - this prints custom error message to stderr
 * @fd: this is the file descriptor
 * @cmd_count: count of commands
 * @s1: First string - name of program
 * @s2: Name of command
 * @s3: this is the custom message to be printed
 * Return: Void
 */

void cus_err_msg(int fd, int cmds_count, char *s1, char *s2, char *s3)
{
	char num;
	int temp = cmds_count;

	while (*s1)
	{
		write(fd, &(*s1), 1), s1++;
	}
	write(fd, ": ", 2);

	if (cmds_count < 10)
	{
		num = cmds_count + '0';
		write(fd, &(num), 1);
	}
	else
	{
		num = (cmds_count / 10) + '0';
		write(fd, &(num), 1);
		num = (temp % 10) + '0';
		write(fd, &(num), 1);
	}
	write(fd, ": ", 2);

	while (*s2)
		write(fd, &(*s2), 1), s2++;

	write(2, ": ", 2);

	while (*s3)
		write(fd, &(*s3), 1), s3++;

	write(fd, "\n", 1);
}
