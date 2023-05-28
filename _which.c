#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
  * _which - Searches for a file in a given path.
  * @filename: Points to a file name to search for and then will be updated if found.
  * @path: The path to search.
  * @nst: Status variable = 1 if founded or -1 else.
  *
  *  Return: Pointer to the found file name if its found, or else NULL .
  */
char *_which(char **filename, const char *path, int *nst)
{
	struct stat st;
	int len_path, len_file;
	char *buf1, *buf2, *name, *sep = "/";

	*nst = -1;
	len_file = _strlen(*filename);
	len_path = _strlen(path);
	name = _strdup(*filename);
	buf1 = _strdup(path);
	buf1 = realloc(buf1, sizeof(*buf1) * (len_path + 2));
	if (buf1 == NULL)
	{
		free(name);
		return (NULL);
	}
	buf1 = _strcat(buf1, sep);
	buf2= _strdup(buf1);
	buf2 = realloc(buf2, sizeof(*buf2) * (len_path + len_file + 2));
	if (buf2 == NULL)
	{
		free(name);
		free(buf1);
		return (NULL);
	}
	buf2 = _strcat(buf2, name);
	if (stat(buf2, &st) == 0)
	{
		*filename = _strdup(buf2);
		*nst = 1;
		free(name);
		free(buf1);
		free(buf2);
		return (*filename);
	}
	free(name);
	free(buf1);
	free(buf2);
	return (NULL);
}
