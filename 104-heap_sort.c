#include "sort.h"

int size_a;

/**
 * swap_values - swaps the values of an arrays indexes
 * @array: pointer to array
 * @first: first index to work on
 * @second: second index to work on
 */
void swap_values(int *array, int first, int second)
{
	int buffer;

	buffer = array[first];
	array[first] = array[second];
	array[second] = buffer;
	print_array(array, size_a);
}

/**
 * max_heapify - this algorithm performs a sidt down procedure
 * to create binary heaps that the root nodes are the maximum
 * compared to it 2 leaf node and the root node is the largest
 * number of the heap
 *
 * @array: array to convert to a binary heap with maximum root nodes
 * @size: size of array
 * @root: index of current binary heap branch root to work on
 *
 * Description:
 * this algorithm works by finding the largest in a binary heap branch and
 * making it the root and recursively do the same thing over again to the prior
 * node that was the node, but unfit to be due to not being the largest.
 * it stops when all root nodes in the binary heap are now the largest of thier
 * branch.
 */
void max_heapify(int *array, int size, int root)
{
	int largest;
	int left_leaf, right_leaf;

	largest = root;
	left_leaf = (root * 2) + 1;
	right_leaf = (root * 2) + 2;

	if (left_leaf < size && array[left_leaf] > array[largest])
		largest = left_leaf;

	if (right_leaf < size && array[right_leaf] > array[largest])
		largest = right_leaf;

	if (largest != root)
	{
		swap_values(array, largest, root);
		max_heapify(array, size, largest);
	}
}

/**
 * init_max_heap- arranges the array to an initailized maximum root
 * based binary heap.
 *
 * @array: pointer to array to be max-heaped
 * @size: size of array
 */
void init_max_heap(int *array, size_t size)
{
	int index;

	for (index = size / 2 - 1; index >= 0 ; index--)
		max_heapify(array, size, index);
}

/**
 * heap_sort - Implementation of Heap Sort Algorithm
 *
 * @array: pointer to array to be sorted
 * @size: size of array
 *
 * Description:
 * this algorithm first converts the array to a maximum root based
 * binary heap by calling `init_max_heap()`
 * given that the largest element of the binary heap will always
 * be the head root and first element of the array, it then runs through
 * the array or binary heap backwards and updates the ending of the array
 * with the first element of the max binary heap and calls `max_heapify()`
 * to reorder the heap to the maximum element based rooted binary heap format
 * after swappping, within every iteration. thereby giving a sorted array.
 */
void heap_sort(int *array, size_t size)
{
	int index;

	size_a = size;
	init_max_heap(array, size);

	for (index = size - 1; index >= 1; index--)
	{
		swap_values(array, index, 0);
		max_heapify(array, index, 0);
	}
}
