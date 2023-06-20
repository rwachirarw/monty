#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: pointer to pointer to first element of stack
 * @line_number: instruction line number
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *iter = NULL;

	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	iter = *head;
	if (iter->prev)
	{
		while (iter->prev)
			iter = iter->prev;
	}
	*head = iter->next;
	if (*head)
		(*head)->prev = NULL;
	free(iter);
}
