#include "monty.h"

/**
 * mod - computes rest of div of second top by top element of the stack
 * @head: pointer to pointer to stack first element
 * @line_number: instruction line number
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *iter = NULL;

	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	iter = *head;
	if (iter->prev)
	{
		while (iter->prev)
			iter = iter->prev;
	}
	*head = iter;
	if ((*head)->next)
	{
		if ((*head)->n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(*head)->next->n = ((*head)->next->n % (*head)->n);
		pop(head, line_number);
		return;
	}
	dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

