#include "monty.h"

/**
 * rotate_right - A program that rotates the stack to the bottom
 * @stack: Pointer to the stack head
 * @line_number: Line number
 */
void rotate_right(Node **stack, __attribute__((unused)) unsigned int counter)
{
	Node *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}

