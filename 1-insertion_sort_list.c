#include "sort.h"

/**
	* insertion_sort_list- insertion sort algorithm to sort a Doubly-Linked list
	* compares the n datum of the nodes to sort
	*	@list: pointer to Doubly-Linked list
	*/

void insertion_sort_list(listint_t **list)
{
	listint_t *buffer, *prev;
	listint_t *current = *list;

	buffer = malloc(sizeof(listint_t));
	prev = malloc(sizeof(listint_t));

	if (buffer == NULL || prev == NULL)
		return;

	while (current != NULL)
	{
		prev = current->prev;
		while ((prev != NULL) && (prev->n > current->n))
		{
			/** buffer for prev ptrs **/
			buffer->next = prev->next;
			buffer->prev = prev->prev;
			/** pushes prev forward **/
			prev->next = current->next;
			prev->prev = current;
			/** from here logic pushes current backward **/
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			/** handles pushing to the beginning **/
			if (buffer->prev == NULL)
			{
				current->prev = NULL;
				*list = current;
			} else
			{
				current->prev = buffer->prev;
				current->prev->next = current;
			}
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
