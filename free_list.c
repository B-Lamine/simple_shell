#include "main.h"
#include <stdlib.h>

/**
  * free_list - frees all nodes of a list.
  * @head: pointer to the list's head.
  */
void free_list(list_t *head)
{
	list_t *last_node = NULL;

	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		free(head->str);
		free(head);
		return;
	}
	last_node = head;
	while (last_node->next->next != NULL)
		last_node = last_node->next;
	free(last_node->next->str);
	free(last_node->next);
	last_node->next = NULL;
	free_list(head);
}

