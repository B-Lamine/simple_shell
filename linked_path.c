#include "main.h"
#include <stdlib.h>

/**
  * linked_path - Creates a linked list of paths from PATH.
  * @head: Start of the linked list.
  * @env: Pointer to the environment variables array.
  *
  * Return: Pointer to the head of the created linked list.
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
