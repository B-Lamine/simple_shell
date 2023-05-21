#include <stdlib.h>
#include "main.h"

/**
  * _strdup - copy a given string into new memory space.
  * @str: string to be copied.
  *
  * Return: address of the new memory space with the copy of the string.
  */
char *_strdup(const char *str)
{
	int i, len;
	char *s;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		*(s + i) = *(str + i);
		i++;
	}
	return (s);
}
