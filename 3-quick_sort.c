#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @array: The array
 * @a: Index of the first element
 * @b: Index of the second element
 * @size: Size of the array
 */
void swap(int *array, size_t a, size_t b, size_t size)
{
	if (a != b)
	{
		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partition the array using Lomuto scheme
 * @array: The array to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Size of the array
 *
 * Return: The index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j, size);
			i++;
		}
	}
	swap(array, i, high, size);
	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts the array using quick sort
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		if (pivot > 0 && pivot > low)
		{
			quick_sort_recursive(array, low, pivot - 1, size);
		}

		if (pivot + 1 < high)
		{
			quick_sort_recursive(array, pivot + 1, high, size);
		}
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quick sort
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
