#include "main.h"
#include <string.h>

/**
  * parse - Tokening a string using a delimiter and stores the tokens in an array.
  * @ar: Pointer to an array of strings where we gonna save thethe tokens.
  * @s: The string to be tokenized.
  * @delim: Delimiter used to split the string into tokens.
  *
  * Return: The number of tokens found and stored in the array.
  */
int parse(char **ar, char *s, char *delim)
{
	char *token, *str;
	int i = 0;

	for (str = s; ; str = NULL)
	{
		token = strtok(str, delim);
		ar[i] = token;
		if (token == NULL)
			break;
		i++;
	}
	return (i);
}
