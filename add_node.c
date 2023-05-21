#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
  * add_node - adds a node to a given list with given data.
  * @head: pointer to the adress of the head of the list,
  * @str: data to be saved in the node.
  * Return: new heads's adress.
  */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(*new));
	if (new ==  NULL)
		return (NULL);
	new->next = *head;
	new->str = strdup(str);
	new->len = _strlen((char *)str);
	*head = new;
	return (*head);
}
