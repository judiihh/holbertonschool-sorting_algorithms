#include <stddef.h>
#include "sort.h"


/**
 * selection_sort - sorts an array using selection sort
 * @array: array to sort
 * @size: Size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, small;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		small = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small])
				small = j;
		}
		if (small != i)
		{
			temp = array[small];
			array[small] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
