#ifndef MONTY_H_INCLUDED
#define MONTY_H_INCLUDED

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct inputs_s - contains inputs of the functions
 * @top: pointer to head of the stack
 * @tail: pointer to the tail of the stack
 * @data: operand of the instruction
 * @flag: checks on the operation mode
 *
 * for stack, queues, LIFO, FIFO
 */
typedef struct inputs_s
{
	stack_t *top;
	stack_t *tail;
	char *data;
	int flag;		/* 1 for stack, 0 for queue mode */
} inputs_t;

extern inputs_t input;

void read_line(instruction_t *instruct, FILE *fd);

/* stack functions implementation */
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void free_stack(stack_t **head);
void sub(stack_t **head, unsigned int line_number);
void div_stack(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void queue(stack_t **head, unsigned int line_number);
void stack(stack_t **head, unsigned int line_number);
void add_node_top(stack_t **head, stack_t *node);
void add_node_end(stack_t **head, stack_t *node);

#endif	/* MONNTY_H_INCLUDED */
