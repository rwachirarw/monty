#include "monty.h"

/**
 * queue - changes the operation mode of the program
 * @head: pointer to pointer of the top of stack
 * @line_number: instruction line number
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	input.flag = 0;
}

/**
 * stack - changes the operation mode of the program
 * @head: pointer to pointer of the top of stack
 * @line_number: instruction line number
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	input.flag = 1;
}
