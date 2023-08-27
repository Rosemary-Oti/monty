#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/

void pop(Node **stack, unsigned int line_number)
{
	Node *hed;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	hed = *stack;
	*stack = hed->next;
	free(hed);
}
