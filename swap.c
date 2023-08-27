#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/

void swap(Node **stack, unsigned int line_number)
{
	Node *hed;
	int len = 0, temp;

	hed = *stack;
	while (hed)
	{
		hed = hed->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	hed = *stack;
	temp = hed->value;
	hed->value = hed->next->value;
	hed->next->value = temp;
}
