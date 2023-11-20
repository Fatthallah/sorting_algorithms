#include "sort.h"

void ff_isp_mot(int *a, int *b);
void bitonic_dom(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_rb3(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * bitonic_dom - fun comment
 * @array: ref comment
 * @size: ref comment
 * @start: ref comment
 * @seq: ref comment
 * @flow: ref comment
 */
void bitonic_dom(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				ff_isp_mot(array + i, array + i + jump);
		}
		bitonic_dom(array, size, start, jump, flow);
		bitonic_dom(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_rb3 - fun comment
 * @array: ref comment
 * @size: ref comment
 * @start: ref comment
 * @seq: ref comment
 * @flow: ref comment
 */
void bitonic_rb3(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_rb3(array, size, start, cut, UP);
		bitonic_rb3(array, size, start + cut, cut, DOWN);
		bitonic_dom(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
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
 * bitonic_sort - fun comment
 * @array: ref comment
 * @size: ref comment
 *
 * Description: desc comment
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_rb3(array, size, 0, size, UP);
}
