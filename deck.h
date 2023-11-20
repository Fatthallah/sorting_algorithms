#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * struct deck_node_s - rere
 * @card: rere
 * @prev: fdfd
 * @next: wqwq
 */
 
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;



/**
 * struct card_s - fdfdf
 * @value: fdfdf
 * @kind: fdfdfd
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;


/**
 * enum kind_e - fdfd
 * @SPADE: fdfd
 * @HEART: fdfd
 * @CLUB: ffd
 * @DIAMOND: fdfdfdfd
 */
 
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;


void sort_deck(deck_node_t **deck);

#endif

