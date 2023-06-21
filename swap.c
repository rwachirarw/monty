#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @head: head of the linked list
 * @line_number: line number
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *head;
	tmp->prev = NULL;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = tmp;
}
