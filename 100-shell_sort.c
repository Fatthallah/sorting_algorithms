#include "sort.h"

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
 * shell_sort - fun comment
 * @array: ref comment
 * @size: ref comment
 * Description: dis comment
 */

void shell_sort(int *array, size_t size)
{
	size_t i;
	size_t gap, j;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				ff_isp_mot(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}

