#include "monty.h"

/**
 * add - A program that adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 *
*/
void add(Node **stack, unsigned int line_number)
{
	Node *hed;
	int len = 0, sum;

	hed = *stack;
	while (hed)
	{
		hed = hed->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	hed = *stack;
	sum = hed->value + hed->next->value;
	hed->next->value = sum;
	*stack = hed->next;
	free(hed);
}
