#include "main.h"
#include <stdlib.h>

char **set_env(char *env[], int *h)
{
	char **env_grid;
	int i = 0, height = 0, len;

	while (env[i])
	{
		height++;
		i++;
	}
	env_grid = alloc_grid(BUFSIZE, height + 1);
	i = 0;
	while (i < height)
	{
		len = _strlen(env[i]);
		env_grid[i] = realloc(env_grid[i], sizeof(char) * (len + 1));
		_strcpy(env_grid[i], env[i]);
		i++;
	}
	free(env_grid[i]);
	env_grid[i] = NULL;
	*h = height;
	return (env_grid);
}
