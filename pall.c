#include "monty.h"
/**
 * pall - prints the stack
 * @stack: stack head
 * @line_number: not used
 * Return: no return
*/

void pall(Node **stack, unsigned int line_number)
{
	Node *hed;
	(void)line_number;

	hed = *stack;
	if (hed == NULL)
		return;
	while (hed)
	{
		printf("%d\n", hed->value);
		hed = hed->next;
	}
}
