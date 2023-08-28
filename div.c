#include "monty.h"

/**
 * divide - Divides the second top element by the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 */
void divide(Node **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	hed = *stack;
	if (hed->value == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = hed->next->value / hed->value;
	hed->next->value = result;
	*stack = hed->next;
	free(hed);
}

