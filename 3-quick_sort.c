
#include "sort.h"


/**
 * swapp- swaps two values in an array
 * @array: data to sort
 * @a: first value
 * @b: second value
 * @size: size of data
 * Return: void
 */
void swapp(int *array, int a, int b, int size)
{
	int temp;

	if (array[a] != array[b])
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * partition - sorts a partition of data in relation to a pivot
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 * Return: New Pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i = min, j, piv = array[max];

	for (j = min; j <= max; j++)
	{
		if (array[j] < piv)
		{
			swapp(array, i, j, size);
			i++;
		}

	}
	swapp(array, i, max, size);

	return (i);
}

/**
 * q_sort - Quick sort algorithm
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: No Return
 */
void q_sort(int *array, int min, int max, size_t size)
{
	int i;

	if (min < max)
	{
		i = partition(array, min, max, size);
		q_sort(array, min, i - 1, size);
		q_sort(array, i + 1, max, size);
	}
}

/**
 * quick_sort -  Quick sort algorithme
 * @array: data to sort
 * @size: size of data
 * Return: No Return
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
