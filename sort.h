#ifndef SORT_H
#define SORT_H

/** libraries **/
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * struct swap_data - metadata datatype to store
 * swapped state and last swapped node;
 * @is_swapped: flag that tells if a swap occurred
 * @current: current node that was swapped
 */
typedef struct swap_data
{
	bool is_swapped;
	listint_t *current;
} swap_data;

/** initial functions **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/** sorting algorithms prototypes **/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

/** my custom function decalrations and datatypes **/
void swap(int *array, int first, int second, size_t size);
void sort_quick(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
/** cocktail_sort **/
void node_swapper(listint_t *current, listint_t *prev, listint_t **list);
listint_t *last_node(listint_t **list);
swap_data forward_sorter(listint_t *current, listint_t **list);
swap_data backward_sorter(listint_t *current, listint_t **list);
/** counting_sort **/
int max_value(int *array, int len);
int key(int element);
int *init_count(int size);
void reorder_array(int *array1, int *array2, int len);
/** merge sort **/
void topdown_split_merge(int *array, int *copy, int start, int end);
void merge(int *array, int *copy, int start, int middle, int end);
void copy_array(int *array, int *copy, size_t start, size_t end);
void print_merge(int *array, size_t start, size_t end, char *flag);

#endif
