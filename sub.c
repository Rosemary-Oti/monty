#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 */
void sub(Node **stack, unsigned int line_number)
{
	Node *t;
	int result, nodes;

	t = *stack;
	for (nodes = 0; t != NULL; nodes++)
		t = t->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	result = t->next->value - t->value;
	t->next->value = result;
	*stack = t->next;
	free(t);
}

