#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element
 * @next: Pointer to the next element
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Provided printing functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

/* Helper functions used by insertion sort */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/* Helper functions for testing in main_0.c */
listint_t *create_listint(const int *array, size_t size);

#endif /* SORT_H */

