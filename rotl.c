#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @head: head
 * @line_number: line number
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void) line_number;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	tmp = *head;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tmp->next->next = NULL;
}
