#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @head: head of the stack
 * @line_number: line number
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void) line_number;
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *head;
	(*head)->prev = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head) = tmp;
}
