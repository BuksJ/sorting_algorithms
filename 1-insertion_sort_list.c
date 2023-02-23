#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr = (*list)->next;

	while (curr != NULL)
	{
		listint_t *prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			/* swap nodes */
			listint_t *tmp = prev->prev;

			prev->prev = curr;
			prev->next = curr->next;
			curr->prev = tmp;
			curr->next = prev;

			if (tmp != NULL)
				tmp->next = curr;

			if (prev->next != NULL)
				prev->next->prev = prev;

			prev = tmp;

			/* print list */
			print_list(*list);
		}

		curr = curr->next;
	}
}
