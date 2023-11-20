#include "sort.h"

void ff_isp_noqta_mn_khalf(listint_t **list, listint_t **tail, listint_t **shaker);
void ff_isp_noqta_ras(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);



/**
 * ff_isp_noqta_mn_khalf - fun comment
 * @list: ref comment
 * @tail: ref comment
 * @shaker: ref comment
 */

void ff_isp_noqta_mn_khalf(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}



/**
 * ff_isp_noqta_ras - fun comment
 * @list: ref comment
 * @tail: ref comment
 * @shaker: ref comment
 */

void ff_isp_noqta_ras(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}



/**
 * cocktail_sort_list - fun comment
 * @list: ref comment
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *shaker;
	bool shaken_not_stirred = false;
	listint_t *tail;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				ff_isp_noqta_ras(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				ff_isp_noqta_mn_khalf(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}

