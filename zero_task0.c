#include "header.h"

/**
 * main1 - Entry
 *
 * Return:0 always
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

