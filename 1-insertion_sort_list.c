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

/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
