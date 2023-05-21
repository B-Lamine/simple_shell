#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
  * add_node_end - adds a node at the end of the given list that stores given
  * data.
  * @head: pointer to address of the head of the list,
  * @str: data to be stored in the new node.
  * Return: address of the new node.
  */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *cursor;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->str = _strdup(str);
	new->len = _strlen(str);
	if (*head == NULL)
		*head = new;
	else
	{
		cursor = *head;
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new;
	}
	return (cursor);
}
