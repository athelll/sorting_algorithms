#include "sort.h"
#include <stdio.h>

/**
 * merge_sort - calls Merge Sort Algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;

	copy_array(array, copy, 0, size);
	topdown_split_merge(array, copy, 0, size);
	free(copy);
}

/**
 * topdown_split_merge - Merge Sort Algoirthm: Top Down Implemntaion
 * @array: array to be sorted
 * @copy: copy of array for comparaison and sort.
 * @start: index of array to sort from
 * @end: index to array to end sort
 *
 * Description:
 * in the function the left and right sub-arrays are recursively
 * sorted and merged such that when retuning to the main call stack
 * the array will be completely sorted.
 */
void topdown_split_merge(int *array, int *copy, int start, int end)
{
	int middle;

	if ((end - start) <= 1)
		return;

	middle = (start + end) / 2;
	topdown_split_merge(array, copy, start, middle);
	topdown_split_merge(array, copy, middle, end);
	merge(array, copy, start, middle, end);
}

/**
 * merge - merges and sort right and left sub-arrays after recusion
 *
 * @array: array to be merged to into
 * @copy: duplicate of original array for comparison
 * @middle: midpoint of array that defines the left and right sub-array to be
 * merged into array.
 * @start: start index of array; array[start:middle] --> right sub-array
 * @end: end index of array: [middle:end] --> left sub-array
 *
 * Description:
 * The conditional checks if the left array is still being merged:
 * meaning it has'nt gotten out of the bounds of the midpoint
 * AND [if the right pointer has exceeded or is at the end of the array;
 * meaning right has completely merged.
 * OR the element of the left pointer is lesser than that of the right.]
 *
 * the conditionals are evaluated in the same order as the main conditional
 * ``` if (left < middle && (right >= end || copy[left] <= copy[right])) ```
 *
 * EXAMPLE:
 *        midddle = 1, end = 3
 *        left = 0, right = 1
 *        copy = [ 9,    5,    6 ] ------> left = [4], right = [6, 5].
 *                 0     1     2  -------> index.
 *                       ^---------------> middle.
 * LOOP
 * 1st iteration, index = 0, left = 0, right = 1:
 *        [0 < 1 AND (1 >= 3) OR 9 < 5]
 *        FALSE.          array[0] = copy[1].       right = right + 1.
 *        array = [5,   5,   6]
 *
 * 2nd iteration, index = 1, left = 0, right = 2:
 *        [0 < 1 AND (2 >= 3) OR 9 < 6]
 *        FALSE.          array[1] = copy[2].       right = right + 1.
 *        array = [5,   6,   6]
 *
 * 3nd iteration, index = 2, left = 0, right = 3:
 *        [0 < 1 AND (3 >= 3) OR 9 < 6]
 *        TRUE.          array[2] = copy[0].        left = left + 1.
 *        array = [5,   6,   9]
 * LOOP-END.
 *
 * sorted and merged array = [5,  6,  9]
 * NOTE: prior this, left and right sub-arrays will already be sorted
 * independently due to previous recusion calls on merge. -felix.
 **/
void merge(int *array, int *copy, int start, int middle, int end)
{
	int index;
	int left, right;

	left = start;
	right = middle;

	printf("Merging...\n");

	for (index = start; index < end; index++)
	{
		if (left < middle && (right >= end || copy[left] <= copy[right]))
			array[index] = copy[left++]; /** post increments **/
		else
			array[index] = copy[right++];
	}

	print_merge(copy, start, middle, "left");
	print_merge(copy, middle, end, "right");
	print_merge(array, start, end, "Done");
	/** update copy array for next recursive merge comparison **/
	copy_array(array, copy, start, end);
}

/**
 * copy_array - copies content of array to copy
 * @array: array to be duplicated
 * @copy: duplicate of array
 * @start: index to start copy
 * @end: index to end copy
 */
void copy_array(int *array, int *copy, size_t start, size_t end)
{
	for (; start < end; start++)
		copy[start] = array[start];
}

/**
 * print_merge - prints left sub-array, right sub-array and resulting
 * merged array for each merge.
 *
 * @array: array to print status from
 * @start: start index
 * @end: end index
 * @flag: state of merge [right, left or Done]
 */
void print_merge(int *array, size_t start, size_t end, char *flag)
{
	size_t i;

	i = start;
	printf("[%s]: ", flag);
	while (array && i < end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
