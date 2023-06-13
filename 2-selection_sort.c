#include "sort.h"

/**
 * swap - swaps the index of elements in a array
 * @array: pointer of array to be re-ordered
 * @a: index of element 1
 * @b: index of element 2
 */
void swap(int *array, size_t a, size_t b)
{
	size_t holder = array[a];

	array[a] = array[b];
	array[b] = holder;
}

/**
 * selection_sort - selection sort algorithm to sort an array
 * @array: pointer to array
 * @size: length of array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, min;

	if (!array || !size || size == 0)
		return;

	if (size == 1)
	{
		print_array(array, size);
		return;
	}

	for (a = 0; a < size - 1; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[min] > array[b])
			{
				min = b;
			}
		}
		if (min != a)
		{
			swap(array, a, min);
			print_array(array, size);
		}
	}
}
