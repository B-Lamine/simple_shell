#include "main.h"

/**
  * _strncmp - compares two strings to a certain given length
  * @s1: Points the first string.
  * @s2: Points the second string.
  * @len: The max length given to do the comparing.
  *
  * Return: The position of the difference between characters of string 1 and string 2.  
  */
int _strncmp(const char *s1, const char *s2, int len)
{
	int i, diff;

	i = 0;
	diff = 0;
	while (i < len)
	{
		if (*(s1 + i) != *(s2 + i))
			diff++;
		i++;
	}
	return (diff);
}
