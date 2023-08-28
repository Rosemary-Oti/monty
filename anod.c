#include "monty.h"

/**
 * add_node - A program that add node to the head stack
 * @stack: Pointer to the stack head
 * @value: New value
 */
void add_node(Node **stack, int value)
{
	Node *new_node, *aux;

	aux = *stack;
	new_node = malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (aux)
		aux->prev = new_node;
	new_node->value = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

