#include <stddef.h>
#include <stdlib.h>

/**
 * _substr - this locates a substring
 * @haystack: string we are search in
 * @needle: substring we are looking for
 *
 * Return: pointer to the substring
 * or NULL not found
 */
char *_substr(char *haystack, char *needle)
{
	int x, y;

	for (x = 0; haystack[x] != '\0'; x++)
	{
		for (y = 0; needle[y] != '\0'; y++)
		{
			if (haystack[x + y] != needle[y])
				break;
		}
		/*if (!needle[y])*/
		if (needle[y] == '\0')
			return (&haystack[x]);
	}
	return (NULL);
}

/**
 * _strlen - Returns the number of characters in string
 * @s: this is the string argument to be counted
 * Return: Always len (Success)
 */

int _strlen(char *s)
{
	int len = 0;
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		len += 1;
	}

	return (len);
}

/**
 * _strdup - copies the string
 * @str: this is the string to duplicate
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */

char *_strdup(char *str)
{
	char *dup;
	unsigned int x, len;

	x = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[x] = str[x]) != '\0')
		x++;

	return (dup);
}
