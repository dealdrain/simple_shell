#include "shell.h"

/**
 * _atoi - this converts a string to an integer
 * @s: string to be converted
 *
 * Return: the integer converted
 */

int _atoi(char *s)
{
	int x, y, z, len, f, digits;

	x = 0, y = 0, z = 0, len = 0;
	f = 0, digits = 0;

	while (s[len] != '\0')
		len++;

	while (x < len && f == 0)
	{
		if (s[x] == '-')
			++y;

		if (s[x] >= '0' && s[x] <= '9')
		{
			digits = s[x] - '0';
			if (y % 2)
				digits = -digits;
			z = z * 10 + digits;
			f = 1;
			if (s[x + 1] < '0' || s[x + 1] > '9')
				break;
			f = 0;
		}
		x++;
	}

	if (f == 0)
		return (0);

	return (z);
}
