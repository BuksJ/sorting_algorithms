#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swap two adjacent elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
