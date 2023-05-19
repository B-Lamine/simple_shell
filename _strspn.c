#include "main.h"

/**
  * _strspn - counts the number of characters in @s before first occurence of
  * character in @accept.
  * @s: pointer to initial string.
  * @accept: pointer to string of accepted characters.
  *
  * Return: number of accepted characters.
  */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, len1, len2;

	len1 = _strlen(s);
	len2 = _strlen(accept);
	i = 0;
	while (i < len2)
	{
		j = 0;
		while (j < len1)
		{
			if (*(s + j) == *(accept + i))
			{
				j++;
				return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
