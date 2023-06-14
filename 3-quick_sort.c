#include "sort.h"

/**
 * swap - swaps two elements indexes
 * @array: pointer to array
 * @first: first index
 * @second: swcond index
 * @size: size of array
 */
void swap(int *array, int first, int second, size_t size)
{
	int buffer;

	if (array[first] == array[second])
		return;

	buffer = array[first];
	array[first] = array[second];
	array[second] = buffer;
	print_array(array, size);
}

/**
 * sort_quick - recursive Quick-Sort Algorithm; calls the partition function
 * @array: pointer to array
 * @low: index of first element
 * @high: index of last element
 * @size: size of array
 */
void sort_quick(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low >= high || low < 0)
		return;

	pivot = partition(array, low, high, size);
	sort_quick(array, low, pivot - 1, size);
	sort_quick(array, pivot + 1, high, size);
}

/**
 * partition - algorithm that performs necessary swaps to partitioned arrays
 * @array: partitioned array
 * @low: index of first element
 * @high: index of last element
 * @size: size of array
 * Return: retuns index of next pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int a;
	int b = low - 1;
	int pivot = array[high];

	for (a = low; a <= high - 1; a++)
	{
		if (array[a] <= pivot)
		{
			b++;
			swap(array, a, b, size);
		}
	}
	b++;
	swap(array, b, high, size);
	return (b);
}

/**
 * quick_sort - Quick-Sort Algorithm
 * @array: pointer to array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (!array || !size || size == 0 || size == 1)
		return;

	low = 0;
	high = size - 1;
	sort_quick(array, low, high, size);
}
