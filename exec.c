#include "monty.h"

/**
 * execute_instruction - A program that executes the opcode
 * @content: Line content
 * @stack: Pointer to the stack
 * @counter: Line number
 * @file: Pointer to the Monty file
 * Return: 0 if successful, 1 if opcode not found
 */
int execute_instruction(char *content, Node **stack, unsigned int counter, FILE *file)
{
	Instruction opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"divide", divide},
		{"multiply", multiply},
		{"modulo", modulo},
		{"print_char", print_char},
		{"print_string", print_string},
		{"rotate_left", rotate_left},
		{"rotate_right", rotate_right},
		{"queue_mode", queue_mode},
		{"stack_mode", stack_mode},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return 0;

	bus.arg = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, counter);
			return 0;
		}
		i++;
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}

