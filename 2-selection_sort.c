#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: pointer to the array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;
    int temp;

    if (!array || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;

        /* Find the minimum element in the unsorted part of the array */
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        /* Swap if the minimum is not the current element */
        if (min_idx != i)
        {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;

            /* Print the array after each swap */
            print_array(array, size);
        }
    }
}

