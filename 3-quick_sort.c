#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for a Quick Sort
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: The size of the array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Implementation of the Lomuto partition
 * @array: The array to be partitioned
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: The size of the array
 * Return: The index of the pivot element
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j);
			print_array(array, size);
			i++;
		}
	}
	swap(array, i, high);
	print_array(array, size);

	return (i);
}


/**
 * swap - swaps two elements in an array
 * @array: the array to sort
 * @i: index of the first element to compare
 * @j: index of the second element to compare
 */

void swap(int *array, int i, int j)
{
	int temp = 0;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
