#include "sort.h"

void ff_isp_mot(int *a, int *b);
int hoare_goz2(int *array, size_t size, int left, int right);
void hoare_rtb(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * hoare_goz2 - fun comment
 * @array: ref comment
 * @size: ref comment
 * @left: ref comment
 * @right: ref comment
 *
 * Return: return comment
 *
 * Description: desc comment
 */
int hoare_goz2(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			ff_isp_mot(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_rtb - fun comment
 * @array: ref comment
 * @size: ref comment
 * @left: ref comment
 * @right: ref comment
 *
 * Description: desc comment
 */
void hoare_rtb(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_goz2(array, size, left, right);
		hoare_rtb(array, size, left, part - 1);
		hoare_rtb(array, size, part, right);
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
 * quick_sort_hoare - fun comment
 * @array: ref comment
 * @size: ref comment
 *
 * Description: desc comment
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_rtb(array, size, 0, size - 1);
}
