#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array (for printing)
 * Return: index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int i = low - 1;
int j, temp;

for (j = low; j < high; j++)
{
if (array[j] < array[high])
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}

if (i + 1 != high)
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}

return (i + 1);
}

/**
 * quick_sort_recursive - Recursively apply quick sort
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = lomuto_partition(array, low, high, size);

quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}

/**
 * quick_sort - Quick sort algorithm using Lomuto partition scheme
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
