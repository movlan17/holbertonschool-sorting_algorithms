#include <stdio.h>
#include "sort.h"

/**
 * swap_int - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: array of integers
 * @low: start index
 * @high: end index
 * @size: size of the array (for printing)
 * Return: final pivot index
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low;
    size_t j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j && array[i] != array[j])
            {
                swap_int(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != high && array[i] != array[high])
    {
        swap_int(&array[i], &array[high]);
        print_array(array, size);
    }
    return i;
}

/**
 * quick_sort_recursive - recursive helper for quick_sort
 * @array: array of integers
 * @low: start index
 * @high: end index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot_index = lomuto_partition(array, low, high, size);

        if (pivot_index > 0) /* prevent underflow */
            quick_sort_recursive(array, low, pivot_index - 1, size);
        quick_sort_recursive(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

