#include "sort.h"

/**
 * ff_isp_noqt - fun comment
 * @h: ref comment
 * @n1: ref comment
 * @n2: ref commebt
 */

void ff_isp_noqt(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}



/**
 * insertion_sort_list - fun comment
 * @list: ref commebt
 * Description: dis comment
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *insert, *iter;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			ff_isp_noqt(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

