#include "sort.h"

/**
 * knuth_index - uses the knuth sequence to find the first gap index
 * to run the shell-sort algorithm
 * @size: size of array
 * Return: index of first gap
 */
int knuth_index(size_t size)
{
	size_t gap = 1;

	while (gap < (size / 3))
		gap = (gap * 3) + 1; /** knuth sequence function **/
	return (gap);
}

/**
 * shell_sort - Shell Sort Algorithm
 * @array: pointer to array
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t a, b, gap;

	if (!array || !size || size == 0 || size == 1)
		return;

	gap = knuth_index(size);
	while (gap > 0) /** iterates through gap sequence **/
	{
		for (a = gap; a < size; a++) /** iterates from gap to arrays end **/
		{
			temp = array[a];
			for (b = a; (b >= gap && (array[b - gap] > temp)); b -= gap)
				array[b] = array[b - gap];
			array[b] = temp;
		}
		gap = (gap - 1) / 3; /** decrements knuth-sequence to previous value **/
		print_array(array, size); /** prints array after gap decrement **/
	}
}
