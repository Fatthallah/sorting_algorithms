#include "sort.h"

void dom_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void dom_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * dom_sort_recursive - fun comment
 * @subarr: ref comment
 * @buff: ref comment
 * @front: ref comment
 * @back: ref comment
 */
void dom_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		dom_sort_recursive(subarr, buff, front, mid);
		dom_sort_recursive(subarr, buff, mid, back);
		dom_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * dom_subarr - fun comment
 * @subarr: ref comment
 * @buff: ref comment
 * @front: ref comment
 * @mid: ref comment
 * @back: ref comment
 */
void dom_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort - fun comment
 * @array: ref comment
 * @size: ref comment
 *
 * Description: desc comment
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	dom_sort_recursive(array, buff, 0, size);

	free(buff);
}
