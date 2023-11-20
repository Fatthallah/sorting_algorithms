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
 * selection_sort - fun comment
 * @array: ref comment
 * @size: ref comment
 * Description: dis comment
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	int *min;
	size_t j;
	
	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;
		if ((array + i) != min)
		{
			ff_isp_mot(array + i, min);
			print_array(array, size);
		}
	}
}

