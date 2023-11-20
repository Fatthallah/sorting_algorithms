#include "deck.h"

int _strmqrna(const char *s1, const char *s2);
char hat_value(deck_node_t *card);
void insertion_sort_deck_no3(deck_node_t **deck);
void insertion_sort_deck_raqm(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * hat_value - fun comment
 * @card: ref comment
 *
 * Return: return comment
 */
char hat_value(deck_node_t *card)
{
	if (_strmqrna(card->card->value, "Ace") == 0)
		return (0);
	if (_strmqrna(card->card->value, "1") == 0)
		return (1);
	if (_strmqrna(card->card->value, "2") == 0)
		return (2);
	if (_strmqrna(card->card->value, "3") == 0)
		return (3);
	if (_strmqrna(card->card->value, "4") == 0)
		return (4);
	if (_strmqrna(card->card->value, "5") == 0)
		return (5);
	if (_strmqrna(card->card->value, "6") == 0)
		return (6);
	if (_strmqrna(card->card->value, "7") == 0)
		return (7);
	if (_strmqrna(card->card->value, "8") == 0)
		return (8);
	if (_strmqrna(card->card->value, "9") == 0)
		return (9);
	if (_strmqrna(card->card->value, "10") == 0)
		return (10);
	if (_strmqrna(card->card->value, "Jack") == 0)
		return (11);
	if (_strmqrna(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_no3 - fun comment
 * @deck: ref comment
 */
void insertion_sort_deck_no3(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_raqm - fun comment
 * @deck: ref comment
 */
void insertion_sort_deck_raqm(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       hat_value(insert) > hat_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * _strmqrna - fun comment
 * @s1: ref comment
 * @s2: ref comment
 *
 * Return: return comment
 */
int _strmqrna(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * sort_deck - fun comment
 * @deck: ref comment
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_no3(deck);
	insertion_sort_deck_raqm(deck);
}
