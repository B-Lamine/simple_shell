#include "main.h"
#include <stddef.h>

/**
  * _strcmp - compares two strings.
  * @s1: first string to be compared.
  * @s2: second string to be compared.
  * Return: integer sum of the difference betwen each characters'
  * ASCII numbers.
  */
int _strcmp(char *s1, char *s2)
{
	int i, diff, len1, len2, len;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = (len1 > len2) ? len2 : len1;
	i = 0;
	diff = 0;
	while (i < len)
	{
		diff = diff + (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (diff);
}
