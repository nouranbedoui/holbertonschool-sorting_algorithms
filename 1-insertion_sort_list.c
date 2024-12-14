#include "sort.h"
/**
 * swap - swap a node for his previous one
 * @node: node
 * @list: node list
 * Return: a pointer
 */
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev;
	listint_t *current = node;

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
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * @list: Dobule linked list to sort
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
