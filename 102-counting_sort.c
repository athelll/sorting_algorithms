#include "sort.h"

/**
 * max_value - returns the maximum value in an array
 *
 * @array: pointer to array
 * @len: length of the array
 * Return: retuns max value
 */
int max_value(int *array, int len)
{
	int max = *array;
	int index;

	for (index = 0; index < len; index++)
	{
		if (array[index] > max)
			max = array[index];
	}
	return (max);
}

/**
 * key - returns the key index of the count array
 * which is just value of the element to be placed
 * in the array; helps for simplicity and
 * code readability. -felix ;]
 *
 * @element: value where the index will be gotten from
 * Return: retuns element
 */
int key(int element)
{
	return (element);
}

/**
 * init_count - allocates memory for count array and
 * initializes all elements to 0;
 *
 * @size: size of array
 * Return: returns pointer to allocated memory
 */
int *init_count(int size)
{
	int a;
	int *count;
	int ZERO = 0;

	count = malloc(sizeof(int) * size);
	if (!count)
		return (NULL);

	for (a = 0; a < size; a++)
		count[a] = ZERO;

	return (count);
}

/**
 * reorder_array - takkes 2 arrays of the same length and updates
 * array 1 with all the values of array 2
 *
 * @array1: array to be updated
 * @array2: array to be updated from
 * @len: length of both arrays
 */
void reorder_array(int *array1, int *array2, int len)
{
	int index;

	for (index = 0; index < len; index++)
		array1[index] = array2[index];
}

/**
 * counting_sort - Implementation of Counting-Sort Algorithm
 *
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count;
	int max_element;
	int a, b;

	max_element = max_value(array, size - 1);
	count = init_count(max_element + 1);
	output = malloc(sizeof(int) * size);

	if (!count || !output || !array || !size)
		return;

	if (size == 0 || size == 1)
		return;

	for (a = 0; a < (int)size; a++)
	{
		b = key(array[a]);
		count[b] = count[b] + 1;
	}

	for (a = 1; a <= max_element; a++)
		count[a] = count[a] + count[a - 1];

	for (a = (size - 1);  a >= 0; a--)
	{
		b = key(array[a]);
		count[b] = count[b] - 1;
		output[count[b]] = array[a];
	}

	print_array(count, max_element + 1);
	reorder_array(array, output, size);
	free(count);
	free(output);
}
