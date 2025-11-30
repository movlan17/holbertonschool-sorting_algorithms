#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to head of list
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    if (a->prev)
        a->prev->next = b;
    else
        *list = b;

    if (b->next)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;

    b->next = a;
    a->prev = b;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: pointer to pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        insert = current->prev;

        while (insert && insert->n > current->n)
        {
            swap_nodes(list, insert, current);
            print_list(*list);
            insert = current->prev;
        }

        current = current->next;
    }
}
