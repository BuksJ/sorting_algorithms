#include "sort.h"

/**
 * lomuto_partition - Use the Lomuto partition scheme to partition the array
 * @array: Array to be sorted
 * @lo: Starting index of the partition to be sorted
 * @hi: Ending index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */

static int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo - 1, j, tmp;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		/* Print the array after each swap */
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @lo: Starting index of the partition to be sorted
 * @hi: Ending index of the partition to be sorted
 * @size: Size of the array
 */

static void quicksort(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = lomuto_partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 * sort algorithm and Lomuto partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
