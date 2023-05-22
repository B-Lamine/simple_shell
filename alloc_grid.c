#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * alloc_grid - create a 2D array an initializes its elements to zero.
  * @width: number of columns.
  * @height: number of rows.
  *
  * Return: a double pointer to a 2D if successful, otherwise NULL.
  */
char **alloc_grid(int width, int height)
{
	int i, j;
	char **pp;

	if (width == 0 || height == 0)
		return (NULL);
	pp = malloc(sizeof(*pp) * height);
	if (pp == NULL)
	{
		free(pp);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		pp[i] = malloc(sizeof(*pp[i]) * width);
		if (pp[i] == NULL)
		{
			j = 0;
			while (j <= i)
			{
				free(pp[j]);
				j++;
			}
			free(pp);
			return (NULL);
		}
		i++;
	}
	i = 0;
	while (i < height)
	{
		j = 0;
		if (j < width)
		{
			*(*(pp + i) + j) = '0';
			j++;
		}
		i++;
	}
	return (pp);
}
