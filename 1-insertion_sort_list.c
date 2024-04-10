#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to a pointer to the head of the linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (current = (*list)->next; current; current = current->next)
	{
		insert = current;
		while (insert->prev && insert->prev->n > insert->n)
		{
			temp = insert->prev;
			if (insert == *list)
			{
				*list = insert;
			}
			if (temp->prev)
			{
				temp->prev->next = insert;
			}
			else
			{
				*list = insert;
			}
			if (insert->next)
			{
				insert->next->prev = temp;
			}
			temp->next = insert->next;
			insert->prev = temp->prev;
			insert->next = temp;
			temp->prev = insert;
			print_list(*list);
		}
	}
}
