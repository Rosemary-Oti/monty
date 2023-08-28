#include "monty.h"

/**
 * queue_mode - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the stack head
 * @line_number: Line number
 */
void queue_mode(Node **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}

