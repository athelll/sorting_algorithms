#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/*
*
*
*/
void insertion_sort_list(listint_t **list)
{
	int a;
	listint_t *buffer;
	listint_t *prev;
	listint_t *current = *list;
	
	while(current != NULL)
	{
		a = current->n;
		prev = current->prev;

		while (prev != NULL && prev->n > a)
		{
			/** buffer for prev ptrs **/
			buffer->next = prev->next;
			buffer->prev = prev->prev;
			/** pushes prev forward **/
			prev->next = current->next;
			prev->prev = current;
			/** pushes current backward **/
			current->next->prev = prev;
			current->next = prev;
			// problematic
			current->prev = buffer->prev;
			current->prev->next = current;
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
		printf("%p\n", current);
	}
}
