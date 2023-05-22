#include "main.h"
#include <stdlib.h>

/**
  * free_grid - frees memory space allocated by alloc_grid for a 2D array.
  * @grid: address of the 2D array.
  * @height: number of rows of the array.
  */
void free_grid(char **grid, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
