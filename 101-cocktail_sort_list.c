#include "sort.h"
#include <stdio.h>

void node_swapper(listint_t *first, listint_t *second, listint_t **list)
{
	listint_t *buffer;

  buffer = malloc(sizeof(listint_t));
	if (buffer == NULL)
		return;

	buffer->next = second->next;
	buffer->prev = first->prev;

	first->next = second->next;
	first->prev = second;

	second->next = first;
	second->prev = buffer->prev;

	if (buffer->prev == NULL)
		*list = second;
	else
		buffer->prev->next = second;

	if (buffer->next != NULL)
		buffer->next->prev = first;

	print_list(*list);
	free(buffer);
}

listint_t* last_node(listint_t **list)
{
	listint_t *node = *list;

	do {
		node = node->next;
	} while (node->next);

	return node;
}

bool forward_sorter(listint_t* current, listint_t **list)
{
	bool swapped = false;

	while(current && current->next)
	{
		if (current->n > current->next->n)
		{
			node_swapper(current, current->next, list);
			swapped = true;
			continue;
		}
		current = current->next;
	}
	return swapped;
}

bool backward_sorter(listint_t* current, listint_t **list)
{
	bool swapped = false;

	while(current && current->prev)
	{
		if (current->n < current->prev->n)
		{
			node_swapper(current->prev, current, list);
			swapped = true;
			continue;
		}
		current = current->prev;
	}
	return swapped;
}

void cocktail_sort_list(listint_t **list)
{
	bool swapped;
	listint_t* head_node = *list;
	listint_t* end_node = last_node(list);

	do {
		swapped = forward_sorter(head_node, list);
		if (!swapped)
			break;
		swapped = backward_sorter(end_node, list);
	} while (swapped);
}
