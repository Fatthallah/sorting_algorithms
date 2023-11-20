#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* comment */
#define UP 0
#define DOWN 1



/**
 * enum bool - comment
 * @false: comment
 * @true: comment
 */
 
typedef enum bool
{
	false = 0,
	true
} bool;



/**
 * struct listint_s - comment
 * @n: comment
 * @prev: comment
 * @next: comment
 */
 
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/* comment */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);



/* comment */
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);



#endif

