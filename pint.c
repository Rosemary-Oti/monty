#include "monty.h"

/**
 * pint - prints the top
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/

void pint(Node **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->value);
}
