#include "sort.h"

void ff_bis_nooaa(int *array, size_t size, int left, int right);
void ff_isp_mot(int *a, int *b);
int ff_bis_taqseem(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


/**
 * ff_bis_nooaa - fun comment
 * @array: ref comment
 * @size: ref comment
 * @left: ref comment
 * @right: ref comment
 * Description: dis comment
 */
void ff_bis_nooaa(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = ff_bis_taqseem(array, size, left, right);
		ff_bis_nooaa(array, size, left, part - 1);
		ff_bis_nooaa(array, size, part + 1, right);
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
 * ff_bis_taqseem - fun comment
 * @array: ref comment
 * @size: ref comment
 * @left: ref comment
 * @right: ref comment
 * Return: ret
 */

int ff_bis_taqseem(int *array, size_t size, int left, int right)
{
	int above, *pivot;
	int below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				ff_isp_mot(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		ff_isp_mot(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}



/**
 * quick_sort - fun comment
 * @array: ref comment
 * @size: ref comment
 * Description: dis comment
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	ff_bis_nooaa(array, size, 0, size - 1);
}

