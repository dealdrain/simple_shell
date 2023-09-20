#include "shell.h"

/**
 * main1 - Entry point of the program
 *
 * Return: 0 Always a success
 */

int main1(void)
{
	int x = 0;

	{
		while (x < 12)

			printf("%d * %d = %d\n", x, x, ++x * x);
	}

	return (0);
}
