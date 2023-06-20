#include "monty.h"

/**
 * add - adds the two top elements of the stack
 * @head: pointer to pointer to stack first element
 * @line_number: instruction line number
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *iter = NULL;

	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
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
		(*head)->next->n = (*head)->n + (*head)->next->n;
		pop(head, line_number);
		return;
	}
	dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
