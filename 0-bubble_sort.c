#include "sort.h"
/**
  * bubble_sort - bubble sort algorithm sort function
  * @array: pointer to array
  * @size: siize of array
  */
void bubble_sort(int *array, size_t size)
{
    bool swapped;
    int buffer;
    size_t n = size, a, b;

    for (a = 0; a < n; a++)
    {
        swapped = false;
        for (b = 0; b < n - 1; b++)
        {
            if (array[b] > array[b + 1])
            {
                buffer = array[b];
                array[b] = array[b + 1];
                array[b + 1] = buffer;
                swapped = true;
                print_array(array, size);
            }
        }
        if (swapped == true)
        continue;
    }
}
