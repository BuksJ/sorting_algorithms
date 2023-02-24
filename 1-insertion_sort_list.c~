#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *prev = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node != NULL)
	{
		prev = node->prev;
		while ((prev != NULL) && (prev->n > node->n))
		{
			prev->next = node->next;
			if (node->next != NULL)
				node->next->prev = prev;
			node->next = prev;
			node->prev = prev->prev;
			prev->prev = node;
			if (node->prev != NULL)
				node->prev->next = node;
			else
				*list = node;
			prev = node->prev;
			print_list(*list);
		}
		node = node->next;
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
