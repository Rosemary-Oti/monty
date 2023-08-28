#include "monty.h"

/**
 * multiply - A prog that multiplies the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 */
void multiply(Node **stack, unsigned int line_number)
{
	Node *hed;
	int len = 0, result;

	hed = *stack;
	while (hed)
	{
		hed = hed->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	hed = *stack;
	result = hed->next->value * hed->value;
	hed->next->value = result;
	*stack = hed->next;
	free(hed);
}

