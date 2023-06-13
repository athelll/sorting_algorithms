#include "sort.h"

/**
	* insertion_sort_list- insertion sort algorithm to sort a Doubly-Linked list
	* compares the n datum of the nodes to sort
	*	@list: pointer to Doubly-Linked list
	*/
void insertion_sort_list(listint_t **list)
{
	listint_t *buffer, *prev, *current = *list;

	buffer = malloc(sizeof(listint_t));
	if (buffer == NULL || !(*list) || !list || current->next == NULL)
		return;

	while (current != NULL)
	{
		prev = current->prev;
		while ((prev != NULL) && (prev->n > current->n)) /** backtracks & compare **/
		{
			buffer->next = prev->next; /** buffer for prev ptrs **/
			buffer->prev = prev->prev;
			prev->next = current->next; /** pushes prev forward **/
			prev->prev = current;

			if (current->next != NULL) /** from here logic pushes current backward **/
				current->next->prev = prev;
			current->next = prev;

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
	free(buffer);
}
