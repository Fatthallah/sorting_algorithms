#include "sort.h"

void ff_isp_mot(int *a, int *b);
void mx_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * mx_heapify - fun comment
 * @array: ref comment
 * @size: ref comment
 * @base: ref comment
 * @root: ref comment
 */
void mx_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		ff_isp_mot(array + root, array + large);
		print_array(array, size);
		mx_heapify(array, size, base, large);
	}
}

/**
 * ff_isp_mot - fun comment
 * @a: ref comment
 * @b: ref comment
 */
void ff_isp_mot(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heap_sort - fun comment
 * @array: ref comment
 * @size: ref comment
 *
 * Description: desc comment
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		mx_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		ff_isp_mot(array, array + i);
		print_array(array, size);
		mx_heapify(array, size, i, 0);
	}
}
