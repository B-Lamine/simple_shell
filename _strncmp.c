#include "main.h"

/**
  *
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
