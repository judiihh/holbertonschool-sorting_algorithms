#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of ints in ascending order
 * @array: Array of ints
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t swap = 0, i;
	int temp;

	do {
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
	} while (swap != 0);
}
