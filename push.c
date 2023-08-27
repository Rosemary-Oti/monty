#include "monty.h"

/**
 * push - A program that adds node to the stack
 * @stack: Stack head
 * @line_number: line_number
 * Return: no return
*/

void push(Node **stack, unsigned int line_number)
{
	int value, t = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			t++;
		for (; bus.arg[t] != '\0'; t++)
		{
			if (bus.arg[t] > 57 || bus.arg[t] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(stack, value);
	else
		add_to_queue(stack, value);
}
