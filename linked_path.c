#include "main.h"
#include <stdlib.h>

/**
  *
  */
list_t *linked_path(list_t **head, char **env)
{
	char *s, *ar[TOK_MAXN], *delim = ":", key[] = "PATH";
	int i = 0;

	s = _getenv(key, env);
	if (s == NULL)
		return (NULL);
	parse(ar, s, delim);
	while (ar[i])
	{
		add_node(head, ar[i]);
		i++;
	}
	free(s);
	return (*head);
}
