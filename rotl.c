#include "monty.h"

/**
 * rotate_left - A program that rotates the stack to the top
 * @stack: Pointer to the stack head
 * @line_number: Line number
 */
void rotate_left(Node **stack, unsigned int line_number)
{
	Node *tmp = *stack, *aux;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}
