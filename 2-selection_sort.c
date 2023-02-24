#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * selection sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	/* Traverse through all array elements */
	for (i = 0; i < size - 1; i++)
	{
		/* Find the minimum element in unsorted array */
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		/* Swap the found minimum element with the first element */
		if (min_idx != i)
		{
			int temp = array[min_idx];

			array[min_idx] = array[i];
			array[i] = temp;
			/* Print array after each swap */
			for (j = 0; j < size; j++)
			{
				printf("%d", array[j]);
				if (j != size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
}
