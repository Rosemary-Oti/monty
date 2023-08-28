#include "monty.h"

/**
 * print_string - Prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the stack head
 * @line_number: Line number
 */
void print_string(Node **stack, unsigned int line_number)
{
	Node *hed;
	(void)line_number;

	hed = *stack;
	while (hed)
	{
		if (hed->value > 127 || hed->value <= 0)
		{
			break;
		}
		printf("%c", hed->value);
		hed = hed->next;
	}
	printf("\n");
}
