#include "sort.h"

int hat_max(int *array, int size);
void radix_counting_ratb(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * radix_counting_ratb - fun comment
 * @array: ref comment
 * @size: ref comment
 * @sig: ref comment
 * @buff: ref comment
 */
void radix_counting_ratb(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * hat_max - fun comment
 * @array: ref comment
 * @size: ref comment
 *
 * Return: return comment
 */
int hat_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_sort - fun comment
 * @array: ref comment
 * @size: ref comment
 *
 * Description: desc comment
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = hat_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_ratb(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
