#include "monty.h"

/**
 * free_stack - A program that frees a doubly linked list
 * @head: Pointer to the head of the stack
 */
void free_stack(Node *head)
{
	Node *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

