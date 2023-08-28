
#include "monty.h"

/**
 * print_char - A program that prints the char at the top o
 * f the stack, followed by a new line
 * @stack: Pointer to the stack head
 * @line_number: Line number
 */
void print_char(Node **stack, unsigned int line_number)
{
	Node *hed;

	hed = *stack;
	if (!hed)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (hed->value > 127 || hed->value < 0)	
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hed->value);
}

