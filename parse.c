#include "main.h"
#include <string.h>

/**
  *
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
