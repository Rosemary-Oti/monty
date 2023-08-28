#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct Node - Doubly linked list representation of a stack (or queue)
 * @value: Integer value of the node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO - Monty project
 */
typedef struct Node
{
	int value;
	struct Node *prev;
	struct Node *next;
} Node;

/**
 * struct Bus - Variables for arguments, file, line content
 * @arg: Argument value
 * @file: Pointer to the Monty file
 * @content: Line content
 * @lifi: Flag to change between stack and queue modes
 *
 * Description: Carries values through the program
 */
typedef struct Bus
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} Bus;

extern Bus bus;

/**
 * struct Instruction - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its associated function
 * for stack, queues, LIFO, FIFO - Monty project
 */
typedef struct Instruction
{
	char *opcode;
	void (*f)(Node **stack, unsigned int line_number);
} Instruction;


/*ssize_t _getline(char **lineptr, size_t *n, FILE *stream);*/
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void push(Node **stack, unsigned int line_number);
void pall(Node **stack, unsigned int line_number);
void pint(Node **stack, unsigned int line_number);
int execute_instruction(char *content, Node **stack,
		unsigned int counter, FILE *file);
void free_stack(Node *head);
void pop(Node **stack, unsigned int counter);
void swap(Node **stack, unsigned int counter);
void add(Node **stack, unsigned int counter);
void nop(Node **stack, unsigned int counter);
void sub(Node **stack, unsigned int counter);
void divide(Node **stack, unsigned int counter);
void multiply(Node **stack, unsigned int counter);
void modulo(Node **stack, unsigned int counter);
void print_char(Node **stack, unsigned int counter);
void print_string(Node **stack, unsigned int counter);
void rotate_left(Node **stack, unsigned int counter);
void rotate_right(Node **stack, __attribute__((unused)) unsigned int counter);
void add_node(Node **stack, int value);
void add_to_queue(Node **stack, int value);
void queue_mode(Node **stack, unsigned int counter);
void stack_mode(Node **stack, unsigned int counter);

#endif
