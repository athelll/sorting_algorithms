#include "sort.h"

/**
 * node_swapper - swaps nodes in a Doubly-linked List
 * @first: first node
 * @second: second node
 * @list: pointer to Doubly-linked list
 */
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

/**
 * forward_sorter - sortes list in forward direction; remembers metadata
 * for each swaps: its swapped state and the last node that was swapped
 *
 * @current: node to begin sort from
 * @list: ppointer to list
 * Return: returns metadata that tells if a swap occured and at what node
 * the last swap occured;
 */
swap_data forward_sorter(listint_t *current, listint_t **list)
{
	swap_data swapped;

	swapped.is_swapped = false;
	while (current && current->next)
	{
		if (current->n > current->next->n)
		{
			node_swapper(current, current->next, list);
			swapped.is_swapped = true;
			swapped.current = current;
			continue;
		}
		current = current->next;
		swapped.current = current;
	}
	return (swapped);
}

/**
 * backward_sorter - sortes list in backward direction; remembers metadata
 * for each swaps: its swapped state and the last node that was swapped
 *
 * @current: node to begin sort from
 * @list: ppointer to list
 * Return: returns metadata that tells if a swap occured and at what node
 * the last swap occured;
 */
swap_data backward_sorter(listint_t *current, listint_t **list)
{
	swap_data swapped;

	swapped.is_swapped = false;
	while (current && current->prev)
	{
		if (current->n < current->prev->n)
		{
			node_swapper(current->prev, current, list);
			swapped.is_swapped = true;
			swapped.current = current;
			continue;
		}
		current = current->prev;
		swapped.current = current;
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Algorithm that applies cocktail sort
 * Doubly-linked lists.
 *
 * @list: pointer to Doubly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped;
	swap_data swapped_data;
	listint_t *head_node = *list;
	listint_t *end_node;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	do {
		swapped_data = forward_sorter(head_node, list);
		swapped = swapped_data.is_swapped;

		if (!swapped)
			break;

		end_node = swapped_data.current;
		swapped_data = backward_sorter(end_node, list);
		swapped = swapped_data.is_swapped;
		head_node = swapped_data.current;
	} while (swapped);
}
