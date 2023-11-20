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
 * bubble_sort - fun comment
 * @array: ref comment
 * @size: reg comment
 * Description: dis comment
 */

void bubble_sort(int *array, size_t size)
{
	bool bubbly = false;
	size_t len = size;
	size_t i;

	if (array == NULL || size < 2)
		return;
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				ff_isp_mot(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}

